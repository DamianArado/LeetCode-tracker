class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n, pprev, prev = len(cost), cost[0], cost[1]
        for i in range (2, n):
            current = cost[i] + min(pprev, prev)
            pprev, prev = prev, current
        return min(pprev, prev);