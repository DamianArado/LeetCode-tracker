class Solution:
    def isBipartiteDFS(self, current: int, color: list, graph: List[List[int]]) -> bool:
        if color[current] == -1: 
            color[current] = 1
        for adjNode in graph[current]:
            if color[adjNode] == -1:
                color[adjNode] = 1 - color[current]
                if self.isBipartiteDFS(adjNode, color, graph) == False:
                    return False
            elif color[adjNode] == color[current]:
                return False
        return True
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n
        for i in range(n):
            if color[i] == -1 and self.isBipartiteDFS(i, color, graph) == False:
                return False
        return True