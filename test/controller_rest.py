from ryu.base import app_manager
from ryu.controller import ofp_event
from ryu.controller.handler import CONFIG_DISPATCHER, MAIN_DISPATCHER
from ryu.controller.handler import set_ev_cls
from ryu.ofproto import ofproto_v1_3
from ryu.lib.packet import packet
from ryu.lib.packet import ethernet
from ryu.app.wsgi import ControllerBase, WSGIApplication, route, Response
from ryu.controller import dpset
import json
import algorithms
from algorithms import start_ant_colony, get_ant_colony_status, stop_ant_colony
import threading
import time
import logging
from ryu.lib import hub
from sdn_topology import read_matrix, visualize_tree
import os
import threading
from collections import defaultdict, deque


# Настройка логгера
logger = logging.getLogger("controller")
logger.setLevel(logging.DEBUG)  # Изменено на DEBUG для детального логгирования
file_handler = logging.FileHandler("controller.log", mode='a', encoding='utf-8')
file_handler.setFormatter(logging.Formatter('%(asctime)s %(levelname)s %(message)s'))
console_handler = logging.StreamHandler()
console_handler.setFormatter(logging.Formatter('%(asctime)s %(levelname)s %(message)s'))
logger.addHandler(file_handler)
logger.addHandler(console_handler)
logger.propagate = False

# === Глобальные переменные для состояния дерева ===
tree_state = {
    'finished': False,
    'edges': [],
    'start': None
}
tree_thread = None

class LearningSwitchRest(app_manager.RyuApp):
    OFP_VERSIONS = [ofproto_v1_3.OFP_VERSION]
    _CONTEXTS = {
        'wsgi': WSGIApplication,
        'dpset': dpset.DPSet
    }

    def __init__(self, *args, **kwargs):
        super(LearningSwitchRest, self).__init__(*args, **kwargs)
        self.mac_to_port = {}
        self.switches = {}
        self.best_path = []
        self.graph = None
        self.lock = threading.Lock()
        self.dpset = kwargs['dpset']
        self.link_map = {}  # Карта связей: {dpid: {neighbor_dpid: out_port}}
        self.switch_index_map = {}  # Соответствие индексов алгоритма к DPID
        self.switch_dpid_to_index = {}  # Обратное соответствие DPID к индексам
        self.scan_interval = 5  # Интервал сканирования топологии
        
        # Регистрация REST контроллера
        wsgi = kwargs['wsgi']
        wsgi.register(LearningSwitchRestController, {'ls_app': self})
        
        # Запуск периодического сканирования топологии
        self.topo_thread = hub.spawn(self._topology_scan_loop)
        
        logger.info("Ryu controller started")

    def _topology_scan_loop(self):
        """Основной цикл сканирования топологии"""
        while True:
            self._scan_topology()
            hub.sleep(self.scan_interval)

    def _scan_topology(self):
        """Сканирование топологии сети"""
        connected_switches = sorted(self.dpset.dps.keys())
        self._update_switch_mapping(connected_switches)
        
        for dpid in connected_switches:
            self._request_ports_info(dpid)
            self._send_lldp_packets(dpid)

    def _update_switch_mapping(self, connected_switches):
        """Обновление соответствия индексов и DPID"""
        self.switch_index_map = {i: dpid for i, dpid in enumerate(connected_switches)}
        self.switch_dpid_to_index = {dpid: i for i, dpid in enumerate(connected_switches)}
        logger.info(f"Switch mapping updated: {self.switch_index_map}")

    def _request_ports_info(self, dpid):
        """Запрос информации о портах коммутатора"""
        datapath = self.dpset.get(dpid)
        if datapath:
            parser = datapath.ofproto_parser
            req = parser.OFPPortDescStatsRequest(datapath, 0)
            datapath.send_msg(req)

    def _send_lldp_packets(self, dpid):
        """Отправка LLDP-пакетов на все порты коммутатора"""
        datapath = self.dpset.get(dpid)
        if datapath:
            # Запрашиваем информацию о портах перед отправкой LLDP
            self._request_ports_info(dpid)

    def _send_lldp_packet(self, datapath, port, dpid):
        """Отправка одного LLDP-пакета"""
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser
        
        # Формируем стандартный LLDP пакет
        pkt = packet.Packet()
        eth = ethernet.ethernet(
            dst='01:80:c2:00:00:0e',  # LLDP multicast
            src='00:00:00:00:00:%02x' % dpid,
            ethertype=0x88cc  # LLDP
        )
        pkt.add_protocol(eth)
        pkt.serialize()
        
        # Добавляем кастомные данные (DPID и порт отправителя)
        lldp_data = dpid.to_bytes(4, byteorder='big') + port.to_bytes(2, byteorder='big')
        full_data = pkt.data + lldp_data
        
        # Отправляем пакет
        actions = [parser.OFPActionOutput(port)]
        out = parser.OFPPacketOut(
            datapath=datapath,
            buffer_id=ofproto.OFP_NO_BUFFER,
            in_port=ofproto.OFPP_CONTROLLER,
            actions=actions,
            data=full_data)
        datapath.send_msg(out)
        #logger.debug(f"Sent LLDP packet from DPID {dpid} port {port}")

    @set_ev_cls(ofp_event.EventOFPPortDescStatsReply, MAIN_DISPATCHER)
    def port_desc_stats_reply_handler(self, ev):
        """Обработчик информации о портах"""
        msg = ev.msg
        dpid = msg.datapath.id
        ofproto = msg.datapath.ofproto
        
        for p in msg.body:
            if p.port_no != ofproto.OFPP_LOCAL:
                #logger.debug(f"Port info - DPID {dpid}: Port {p.port_no}")
                # Отправляем LLDP на каждый не-локальный порт
                self._send_lldp_packet(msg.datapath, p.port_no, dpid)

    @set_ev_cls(ofp_event.EventOFPPacketIn, MAIN_DISPATCHER)
    def packet_in_handler(self, ev):
        """Обработчик входящих пакетов"""
        msg = ev.msg
        datapath = msg.datapath
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser
        in_port = msg.match['in_port']
        pkt = packet.Packet(msg.data)
        eth = pkt.get_protocol(ethernet.ethernet)
        
        # Обработка LLDP-пакетов
        if eth.ethertype == 0x88cc:  # LLDP
            self._process_lldp_packet(msg, datapath, in_port)
            return

        # Learning switch логика
        self._handle_regular_packet(datapath, in_port, eth, msg)

    def _process_lldp_packet(self, msg, datapath, in_port):
        """Обработка LLDP-пакета для построения топологии"""
        try:
            data = msg.data
            src_dpid = int.from_bytes(data[-6:-2], byteorder='big')  # Последние 4 байта перед портом
            src_port = int.from_bytes(data[-2:], byteorder='big')    # Последние 2 байта - порт
            dst_dpid = datapath.id
            
            #logger.info(f"Discovered link: {src_dpid}:{src_port} -> {dst_dpid}:{in_port}")
            
            # Обновляем карту связей
            with self.lock:
                self.link_map.setdefault(src_dpid, {})
                self.link_map.setdefault(dst_dpid, {})
                self.link_map[src_dpid][dst_dpid] = src_port
                self.link_map[dst_dpid][src_dpid] = in_port
                
            #logger.debug(f"Link map updated: {self.link_map}")
            
        except Exception as e:
            logger.error(f"LLDP processing error: {str(e)}")

    def _handle_regular_packet(self, datapath, in_port, eth, msg):
        """Обработка обычных пакетов (learning switch)"""
        ofproto = datapath.ofproto  # Получаем ofproto из datapath
        parser = datapath.ofproto_parser
        dpid = datapath.id

        self.mac_to_port.setdefault(dpid, {})

        # Игнорируем multicast
        if eth.dst.startswith("33:33"):
            return

        self.mac_to_port[dpid][eth.src] = in_port

        if eth.dst in self.mac_to_port[dpid]:
            out_port = self.mac_to_port[dpid][eth.dst]
        else:
            out_port = ofproto.OFPP_FLOOD

        self._forward_packet(datapath, in_port, out_port, eth.dst, msg)

    def _forward_packet(self, datapath, in_port, out_port, eth_dst, msg):
        """Пересылка пакета и установка flow-правил"""
        ofproto = datapath.ofproto  # Добавьте эту строку
        parser = datapath.ofproto_parser
        actions = [parser.OFPActionOutput(out_port)]

        if out_port != ofproto.OFPP_FLOOD:
            match = parser.OFPMatch(in_port=in_port, eth_dst=eth_dst)
            self.add_flow(datapath, 1, match, actions)

        data = None
        if msg.buffer_id == ofproto.OFP_NO_BUFFER:
            data = msg.data

        out = parser.OFPPacketOut(
            datapath=datapath, buffer_id=msg.buffer_id, in_port=in_port,
            actions=actions, data=data)
        datapath.send_msg(out)
        logger.debug(f"PacketOut: dpid={datapath.id}, in_port={in_port}, out_port={out_port}")

    def add_flow(self, datapath, priority, match, actions, buffer_id=None):
        """Установка flow-правила"""
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser
        inst = [parser.OFPInstructionActions(ofproto.OFPIT_APPLY_ACTIONS, actions)]
        
        mod = parser.OFPFlowMod(
            datapath=datapath,
            priority=priority,
            match=match,
            instructions=inst,
            buffer_id=buffer_id if buffer_id else ofproto.OFP_NO_BUFFER
        )
        datapath.send_msg(mod)
        logger.debug(f"FlowMod added: dpid={datapath.id}, priority={priority}")

    @set_ev_cls(ofp_event.EventOFPSwitchFeatures, CONFIG_DISPATCHER)
    def switch_features_handler(self, ev):
        """Обработчик подключения коммутатора"""
        datapath = ev.msg.datapath
        dpid = datapath.id
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser
        
        self.switches[dpid] = datapath
        logger.info(f"Switch connected: DPID={dpid}")
        
        # Устанавливаем правило для обработки LLDP
        match = parser.OFPMatch(eth_type=0x88cc)
        actions = [parser.OFPActionOutput(ofproto.OFPP_CONTROLLER)]
        self.add_flow(datapath, 10, match, actions)
        
        # Правило по умолчанию
        match = parser.OFPMatch()
        actions = [parser.OFPActionOutput(ofproto.OFPP_CONTROLLER)]
        self.add_flow(datapath, 0, match, actions)

    def install_path_flows(self, best_path):
        """Установка flow-правил для оптимального пути"""
        if not best_path:
            logger.error("Empty path provided")
            return
            
        logger.info(f"Installing flows for path: {best_path}")
        
        try:
            path_dpids = [self.switch_index_map[idx] for idx in best_path]
            logger.info(f"Path DPIDs: {path_dpids}")
            
            for i in range(len(path_dpids)-1):
                src_dpid = path_dpids[i]
                dst_dpid = path_dpids[i+1]
                
                logger.info(f"Processing segment: {src_dpid} -> {dst_dpid}")
                
                if src_dpid not in self.link_map or dst_dpid not in self.link_map[src_dpid]:
                    logger.error(f"No link between {src_dpid} and {dst_dpid}")
                    logger.info(f"Available links: {self.link_map.get(src_dpid, {})}")
                    continue
                    
                datapath = self.switches.get(src_dpid)
                if not datapath:
                    logger.error(f"Datapath not found for DPID {src_dpid}")
                    continue
                    
                out_port = self.link_map[src_dpid][dst_dpid]
                self._install_path_flow(datapath, out_port, dst_dpid)
                
        except Exception as e:
            logger.error(f"Error installing path flows: {str(e)}")

    def _install_path_flow(self, datapath, out_port, dst_dpid):
        """Установка конкретного flow-правила для пути"""
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser
        
        match = parser.OFPMatch()
        actions = [parser.OFPActionOutput(out_port)]
        inst = [parser.OFPInstructionActions(ofproto.OFPIT_APPLY_ACTIONS, actions)]
        
        mod = parser.OFPFlowMod(
            datapath=datapath,
            priority=100,  # Высокий приоритет для path flows
            match=match,
            instructions=inst,
            table_id=0,
            command=ofproto.OFPFC_ADD,
            idle_timeout=0,
            hard_timeout=0
        )
        datapath.send_msg(mod)
        logger.info(f"Path flow installed: DPID {datapath.id} -> port {out_port} (to DPID {dst_dpid})")


class LearningSwitchRestController(ControllerBase):
    def __init__(self, req, link, data, **config):
        super(LearningSwitchRestController, self).__init__(req, link, data, **config)
        self.ls_app = data['ls_app']

    @route('antcolony_start', '/antcolony/start', methods=['POST'])
    def antcolony_start(self, req, **kwargs):
        logger.info("===== ANT COLONY START REQUEST =====")
        params = req.json if req.body else {}
        
        try:
            # Проверка обязательных параметров
            required_params = ['num_ants', 'num_iterations', 'alpha', 'beta', 
                             'evaporation', 'Q', 'start', 'end', 'percentage']  # Добавлен percentage
            missing_params = [p for p in required_params if p not in params]
            if missing_params:
                error_msg = f"Missing required parameters: {', '.join(missing_params)}"
                logger.error(error_msg)
                return Response(status=400, body=error_msg)
            
            # Извлечение параметров
            num_ants = int(params['num_ants'])
            num_iterations = int(params['num_iterations'])
            alpha = float(params['alpha'])
            beta = float(params['beta'])
            evaporation = float(params['evaporation'])
            Q = float(params['Q'])
            start_idx = int(params['start'])
            end_idx = int(params['end'])
            percentage = int(params['percentage'])
            
            # Проверка индексов
            connected_switches = sorted(self.ls_app.dpset.dps.keys())
            n = len(connected_switches)
            
            if start_idx < 0 or start_idx >= n or end_idx < 0 or end_idx >= n:
                error_msg = f"Invalid start/end points: start={start_idx}, end={end_idx}, valid range=0-{n-1}"
                logger.error(error_msg)
                return Response(status=400, body=error_msg)
            
            # Чтение метрик из файла
            metric_file_path = os.path.join(os.path.dirname(__file__), '/home/stu/SDN/test/metric_data.txt')
            logger.info(f"Reading metrics from file: {metric_file_path}")
            logger.info(f"Percentage of convergence: {percentage}")
    
            try:
                matrix = read_matrix(n, metric_file_path)[0]  # Используем первую матрицу (задержки)
                logger.info(f"Using adjacency matrix of size {len(matrix)}x{len(matrix[0])}")
            except Exception as e:
                error_msg = f"Error reading metrics: {str(e)}"
                logger.error(error_msg)
                return Response(status=500, body=error_msg)
            
            # Запуск алгоритма
            logger.info("Starting ant colony optimization")
            start_ant_colony(num_ants, num_iterations, alpha, beta, evaporation, Q, 
                           start_idx, end_idx, matrix, percentage)
            
            # Мониторинг выполнения
            hub.spawn(self._monitor_algorithm)
            
            return Response(content_type='application/json',
                          body=json.dumps({
                              'status': 'started',
                              'switches': n,
                              'start': start_idx,
                              'end': end_idx
                          }))
        
        except Exception as e:
            logger.error(f"Unexpected error: {str(e)}")
            return Response(status=500, body=f'Internal server error: {str(e)}')

    def _monitor_algorithm(self):
        """Мониторинг выполнения алгоритма"""
        try:
            logger.info("Algorithm monitoring started")
            while True:
                status = get_ant_colony_status()
                if status is None:
                    logger.error("Algorithm failed to start")
                    break
                    
                if status.get('finished'):
                    best_path = status.get('best_path')
                    if best_path:
                        logger.info(f"Optimization complete! Best path: {best_path}")
                        self.ls_app.install_path_flows(best_path)
                    else:
                        logger.error("Algorithm finished but no path found")
                    break
                hub.sleep(0.5)
        except Exception as e:
            logger.error(f"Algorithm monitoring error: {str(e)}")

    @route('antcolony_status', '/antcolony/status', methods=['GET'])
    def antcolony_status(self, req, **kwargs):
        logger.info("===== ANT COLONY STATUS REQUEST =====")
        try:
            status = get_ant_colony_status() or {}
            status.update({
                'switch_mapping': self.ls_app.switch_index_map,
                'timestamp': time.time()
            })
            return Response(content_type='application/json', body=json.dumps(status))
        except Exception as e:
            logger.error(f"Status check error: {str(e)}")
            return Response(status=500, body='Internal server error')

    @route('antcolony_stop', '/antcolony/stop', methods=['POST'])
    def antcolony_stop(self, req, **kwargs):
        logger.info("===== ANT COLONY STOP REQUEST =====")
        try:
            stop_ant_colony()
            return Response(content_type='application/json', 
                          body=json.dumps({'status': 'stopped'}))
        except Exception as e:
            logger.error(f"Stop error: {str(e)}")
            return Response(status=500, body='Internal server error')

    @route('antcolony_tree', '/antcolony/tree', methods=['POST'])
    def antcolony_tree(self, req, **kwargs):
        global tree_state, tree_thread
        logger.info("===== ANT COLONY TREE REQUEST =====")
        params = req.json if req.body else {}
        try:
            required_params = ['num_ants', 'num_iterations', 'alpha', 'beta', 'evaporation', 'Q', 'start', 'percentage']
            missing_params = [p for p in required_params if p not in params]
            if missing_params:
                error_msg = f"Missing required parameters: {', '.join(missing_params)}"
                logger.error(error_msg)
                return Response(status=400, body=error_msg)
            num_ants = int(params['num_ants'])
            num_iterations = int(params['num_iterations'])
            alpha = float(params['alpha'])
            beta = float(params['beta'])
            evaporation = float(params['evaporation'])
            Q = float(params['Q'])
            start_idx = int(params['start'])
            percentage = int(params['percentage'])
            connected_switches = sorted(self.ls_app.dpset.dps.keys())
            n = len(connected_switches)
            if start_idx < 0 or start_idx >= n:
                error_msg = f"Invalid start point: start={start_idx}, valid range=0-{n-1}"
                logger.error(error_msg)
                return Response(status=400, body=error_msg)
            metric_file_path = os.path.join(os.path.dirname(__file__), '/home/stu/SDN/test/metric_data.txt')
            matrix = read_matrix(n, metric_file_path)[0]
            logger.info("Starting ant colony tree search")

            # Сброс состояния дерева
            tree_state = {
                'finished': False,
                'edges': [],
                'start': start_idx
            }

            def run_tree():
                global tree_state
                all_paths = algorithms.ant_colony_tree(num_ants, num_iterations, alpha, beta, evaporation, Q, start_idx, matrix, percentage)
                # Преобразуем пути в рёбра
                edges = []
                parent = {}
                def find(u):
                    while parent[u] != u:
                        parent[u] = parent[parent[u]]
                        u = parent[u]
                    return u
                def union(u, v):
                    pu, pv = find(u), find(v)
                    if pu == pv:
                        return False
                    parent[pu] = pv
                    return True
                # Инициализация DSU
                nodes = set()
                for path in all_paths:
                    for v in path:
                        nodes.add(v)
                for v in nodes:
                    parent[v] = v
                # Добавляем рёбра только если они не образуют цикл
                for path in all_paths:
                    for i in range(len(path) - 1):
                        u, v = path[i], path[i+1]
                        if union(u, v):
                            edge = [u, v]
                            if edge not in edges and edge[::-1] not in edges:
                                edges.append(edge)
                # Логирование количества вершин и рёбер
                logger.info(f"Tree node count: {len(nodes)}")
                logger.info(f"Tree edge count: {len(edges)}")
                logger.info(f"Tree edges: {edges}")

                # Проверка на дубли и циклы в edges
                def has_duplicate_edges(edges):
                    seen = set()
                    for u, v in edges:
                        key = tuple(sorted((u, v)))
                        if key in seen:
                            return True
                        seen.add(key)
                    return False

                def has_cycle(edges, node_count):
                    parent = {}
                    def find(u):
                        while parent[u] != u:
                            parent[u] = parent[parent[u]]
                            u = parent[u]
                        return u
                    def union(u, v):
                        pu, pv = find(u), find(v)
                        if pu == pv:
                            return True  # цикл
                        parent[pu] = pv
                        return False
                    nodes = set()
                    for u, v in edges:
                        nodes.add(u)
                        nodes.add(v)
                    for v in nodes:
                        parent[v] = v
                    for u, v in edges:
                        if union(u, v):
                            return True
                    return False

                if has_duplicate_edges(edges):
                    logger.error("Дублирующиеся рёбра обнаружены в дереве!")
                if has_cycle(edges, len(nodes)):
                    logger.error("ВНИМАНИЕ: В дереве обнаружен цикл!")
                if len(edges) != len(nodes) - 1:
                    logger.warning(f"ВНИМАНИЕ: В дереве {len(edges)} рёбер, а должно быть {len(nodes)-1}")

                tree_state['edges'] = edges

                # Восстановление корректных путей от корня до всех вершин дерева (BFS)
                graph = defaultdict(list)
                for u, v in edges:
                    graph[u].append(v)
                    graph[v].append(u)
                all_paths_tree = []
                visited = set()
                queue = deque([(start_idx, [start_idx])])
                while queue:
                    node, path = queue.popleft()
                    visited.add(node)
                    is_leaf = True
                    for neighbor in graph[node]:
                        if neighbor not in visited:
                            queue.append((neighbor, path + [neighbor]))
                            is_leaf = False
                    if is_leaf:
                        all_paths_tree.append(path)
                logger.info(f"All tree paths: {all_paths_tree}")
                tree_state['all_paths'] = all_paths_tree

                tree_state['finished'] = True
                logger.info(f"Tree search finished, edges: {edges}")
                # Визуализация дерева
                visualize_tree(edges)

            # Запуск в отдельном потоке
            
            tree_thread = threading.Thread(target=run_tree)
            tree_thread.start()

            return Response(content_type='application/json',
                            body=json.dumps({'status': 'started', 'start': start_idx}))
        except Exception as e:
            logger.error(f"Unexpected error: {str(e)}")
            return Response(status=500, body=f'Internal server error: {str(e)}')

    @route('antcolony_status_tree', '/antcolony/status_tree', methods=['GET'])
    def antcolony_status_tree(self, req, **kwargs):
        global tree_state
        # Возвращаем текущее состояние построения дерева
        return Response(content_type='application/json', body=json.dumps(tree_state))
