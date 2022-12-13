class Solution:
    def countHousePlacements(self, n: int) -> int:
        if n == 1: return 4
        if n == 2: return 9
        pprev, prev, mod = 2, 3, pow(10, 9) + 7
        for i in range (3, n + 1):
            current = (pprev + prev)
            pprev, prev = prev, current
        return (prev * prev) % mod