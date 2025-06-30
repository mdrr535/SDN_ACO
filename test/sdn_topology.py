import re
import socket

def open_connection():
    """
    Функция создает подключение к SDN Topology
    """ 
    sdn_topology_socket = socket.socket()
    sdn_topology_socket.settimeout(10.0)
    sdn_topology_socket.connect(('127.0.0.1', 6111))

    return sdn_topology_socket

def __read_metrics(metric_data_file_name):
    """
    Функция возвращает метрики каналов связи
    Аргументы:
    metric_data_file_name -- файл с данными о метриках каналов связи
    """ 
    metric_data_file = open(metric_data_file_name, 'r')
    metric_data_file_lines = metric_data_file.readlines()
    metric_data_file.close()
 
    NODE1 = 'node1'
    NODE2 = 'node2'
    METRIC1 = 'metric1'
    METRIC2 = 'metric2'
    METRIC3 = 'metric3'

    metrics = []
    for line in metric_data_file_lines:
        groupdict = re.search(f'(?P<{NODE1}>\d+)-(?P<{NODE2}>\d+):(?P<{METRIC1}>\d+),(?P<{METRIC2}>\d+),(?P<{METRIC3}>\d+)', line).groupdict()
        metrics.append([int(groupdict[NODE1]), int(groupdict[NODE2]), int(groupdict[METRIC1]), int(groupdict[METRIC2]), int(groupdict[METRIC3])])
    #print(metrics)

    return metrics


def read_matrix(size, metric_data_file):
    """
    Функция возвращает три матрицы смежности графа сети по задержке,
    пропускной способности и проценту потерь пакетов
    Аргументы:
    size -- количество OpenFLow коммутаторов
    metric_data_file_name -- файл с данными о метриках каналов связи    
    """ 
    metrics = __read_metrics(metric_data_file)
    #print(metrics)
    graph = []
    
    for i in range(3): 
        graph.append([])
    #print(graph)
        
    for k in range(3):
        for i in range(size):
            graph[k].append([])
            for j in range(size):
                graph[k][i].append(0)


        for link in metrics:
            vertex1 = link[0] - 1
            vertex2 = link[1] - 1
            weight = link[2+k]
            graph[k][vertex1][vertex2] = weight

    return graph


def visualize_tree(edges):
    """
    Функция визуализирует дерево, составленное из ребер
    Аргументы:
    edges -- список ребер в формате [[1, 2], [2, 3], [3, 4]]
    """ 
    message = 'Trees#'
    for i in range(len(edges)):
        message += str(edges[i][0] + 1)
        message += '-'
        message += str(edges[i][1] + 1)
        message += ','
    #print(message)
    message = bytes(message, 'utf-8')
    sdn_topology_socket = open_connection()
    sdn_topology_socket.send(message)
    sdn_topology_socket.close()

    
def visualize_routs(routs):
    """
    Функция визуализирует маршруты, проходящие через коммутаторы
    Аргументы:
    routs -- список маршрутов из коммутаторов в формате [[0, 1, 2], [0, 3, 4]] - два маршрута
    """ 
    message = 'Paths#'
    for i in range(len(routs)):
        for j in range(len(routs[i])):
            message += str(routs[i][j] + 1)
            message += ","
        message += ";"

    message = bytes(message, 'utf-8')
    #print(message)

    sdn_topology_socket = open_connection()
    sdn_topology_socket.send(message)
    sdn_topology_socket.close()


def visualize_segments(segments):
    """
    Функция визуализирует сегменты коммутаторов
    Аргументы:
    segments -- сегменты коммутаторов [[0, 1, 2], [3, 4, 5]]
    """ 
    message = 'Islands#'
    for i in range(len(segments)):
        for j in range(len(segments[i])):
            message += str(segments[i][j]+1)
            message += ','
        message += ';'
        
    message = bytes(message, 'utf-8')
    #print(message)
    
    sdn_topology_socket = open_connection()
    sdn_topology_socket.send(message)
    sdn_topology_socket.close()
