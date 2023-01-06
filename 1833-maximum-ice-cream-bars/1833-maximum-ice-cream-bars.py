class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs = sorted(costs)
        iceCream = i = 0
        while i < len(costs) and coins >= costs[i]:
            coins -= costs[i]
            i, iceCream = i + 1, iceCream + 1
        return iceCream