class Solution:
    def bipartite(self, current: int, color: List[int], graph: List[List[int]]) -> bool:
        if color[current] == -1: 
            color[current] = 1
        for adjNode in graph[current]:
            if color[adjNode] == -1:
                color[adjNode] = 1 - color[current]
                if not self.bipartite(adjNode, color, graph):
                    return False
            elif color[adjNode] == color[current]:
                return False
        return True
    
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * (n)
        for i in range(n):
            if color[i] == -1 and not self.bipartite(i, color, graph):
                return False
        return True