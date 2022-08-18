class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        result, N, R = 1, m + n - 2, min(m - 1, n - 1)
        for i in range (1, R + 1):
            result = result * (N - R + i) // i
        return result
        