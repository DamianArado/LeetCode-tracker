from queue import Queue

class Solution:
    def isBipartiteBFS(self, current: int, color: list, graph: List[List[int]]) -> bool:
        q = Queue()
        if color[current] == -1:
            color[current] = 1
        q.put(current)
        while not q.empty():
            current = q.get()
            for adjNode in graph[current]:
                if color[adjNode] == -1:
                    color[adjNode] = 1 - color[current]
                    q.put(adjNode)
                elif color[adjNode] == color[current]:
                    return False
        return True
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n
        for i in range(n):
            if color[i] == -1 and not self.isBipartiteBFS(i, color, graph):
                return False
        return True