class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        graph = defaultdict(list)
        n = len(points)
        for i in range(n):
            for j in range(i+1, n):
                dist = self.manhattanDist(points[i], points[j])
                graph[i].append([j, dist])
                graph[j].append([i, dist])

        return self.primMST(graph, n, 0)

    def manhattanDist(self, p1, p2):
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    def primMST(self, graph, n, src):
        seen = set()
        minHeap = [[0, src]]  # pair of (dist, vertex)
        mstDist = 0

        while len(seen) < n:
            dist, u = heappop(minHeap)
            if u in seen: continue  # skip if this node is already included in MST
            seen.add(u)  # add this node to MST
            mstDist += dist
            for v, d in graph[u]:
                if v not in seen:
                    heappush(minHeap, [d, v])
        return mstDist