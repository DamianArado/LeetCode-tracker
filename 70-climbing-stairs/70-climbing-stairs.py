class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0 or n == 1: return 1
        prev = prev2 = 1
        for i in range (2, n + 1):
            current = prev + prev2
            prev2 = prev
            prev = current
        return prev