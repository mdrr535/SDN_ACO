import threading
import time
import numpy as np
import random

class AntColonyState:
    def __init__(self, num_ants, num_iterations, alpha, beta, evaporation, Q, start, end, graph, percentage):
        self.num_ants = num_ants
        self.num_iterations = num_iterations
        self.alpha = alpha
        self.beta = beta
        self.evaporation = evaporation
        self.Q = Q
        self.start = start
        self.end = end
        self.graph = graph
        self.N = len(graph)
        self.percentage = percentage
        self.current_iter = 0
        self.best_path = []
        self.best_length = float('inf')
        self.pheromone = np.ones((self.N, self.N))
        self.distance = np.array(graph)
        self.running = False
        self.lock = threading.Lock()
        self.finished = False

    def step(self):
        with self.lock:
            all_paths = []
            all_lengths = []
            for ant in range(self.num_ants):
                path, length = self._construct_path()
                if path and length < self.best_length:
                    self.best_length = length
                    self.best_path = path
                if path:
                    all_paths.append(path)
                    all_lengths.append(length)
            self.pheromone *= (1.0 - self.evaporation)
            for path, length in zip(all_paths, all_lengths):
                if length > 0:
                    for i in range(len(path) - 1):
                        u, v = path[i], path[i+1]
                        self.pheromone[u][v] += self.Q / length
                        self.pheromone[v][u] += self.Q / length
            self.current_iter += 1
            
            # Проверка достижения процента сходимости
            current_percentage = (self.current_iter / self.num_iterations) * 100
            if current_percentage >= 70: #self.percentage
                self.finished = True
            
            
            if self.current_iter >= self.num_iterations:
                self.finished = True

    def _construct_path(self):
        visited = [False] * self.N
        path = [self.start]
        visited[self.start] = True
        current = self.start
        length = 0.0
        for _ in range(self.N * 2):
            if current == self.end:
                break
            candidates = [j for j in range(self.N) if self.distance[current][j] > 0 and not visited[j]]
            if not candidates:
                return None, float('inf')
            probs = []
            for j in candidates:
                tau = self.pheromone[current][j] ** self.alpha
                eta = (1.0 / self.distance[current][j]) ** self.beta
                probs.append(tau * eta)
            probs_sum = sum(probs)
            if probs_sum == 0:
                return None, float('inf')
            probs = [p / probs_sum for p in probs]
            next_node = random.choices(candidates, weights=probs, k=1)[0]
            length += self.distance[current][next_node]
            current = next_node
            path.append(current)
            visited[current] = True
        if current == self.end:
            return path, length
        else:
            return None, float('inf')

    def is_finished(self):
        with self.lock:
            return self.finished

    def get_status(self):
        with self.lock:
            return {
                'iteration': self.current_iter,
                'best_path': self.best_path,
                'best_length': self.best_length,
                'finished': self.finished
            }

# Глобальный объект для хранения состояния алгоритма
ant_colony_state = None
ant_colony_thread = None

def start_ant_colony(num_ants, num_iterations, alpha, beta, evaporation, Q, start, end, graph, percentage, delay=0.3):
    global ant_colony_state, ant_colony_thread
    ant_colony_state = AntColonyState(num_ants, num_iterations, alpha, beta, evaporation, Q, start, end, graph, percentage)
    def run():
        while not ant_colony_state.is_finished():
            ant_colony_state.step()
            time.sleep(delay)
    ant_colony_thread = threading.Thread(target=run)
    ant_colony_thread.start()

def get_ant_colony_status():
    global ant_colony_state
    if ant_colony_state is not None:
        return ant_colony_state.get_status()
    else:
        return None

def stop_ant_colony():
    global ant_colony_state, ant_colony_thread
    if ant_colony_state is not None:
        ant_colony_state.finished = True
    if ant_colony_thread is not None:
        ant_colony_thread.join()
        ant_colony_thread = None
    ant_colony_state = None

def ant_colony_tree(num_ants, num_iterations, alpha, beta, evaporation, Q, start, graph, percentage, delay=0.3):
    N = len(graph)
    all_paths = []
    for end in range(N):
        if end == start:
            continue
        state = AntColonyState(num_ants, num_iterations, alpha, beta, evaporation, Q, start, end, graph, percentage)
        for _ in range(num_iterations):
            state.step()
            time.sleep(delay)
        if state.best_path:
            all_paths.append(state.best_path)
    return all_paths