class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        minCost, n, mult = 0, len(cost), 0
        cost = sorted(cost)
        for i in range (n - 1, -1, -1):
            if mult == 2: mult = 0
            elif mult < 2:
                minCost += cost[i]
                mult += 1
        return minCost