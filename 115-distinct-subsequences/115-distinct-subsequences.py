class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n1 = len(s)
        n2 = len(t)
        dp = [0] * (n2 + 1)
        dp[0] = 1
        for idx1 in range (1, n1 + 1):
            current = [0] * (n2 + 1)
            current[0] = 1
            for idx2 in range (1, n2 + 1):
                take = dp[idx2 - 1]
                notTake = dp[idx2]
                if s[idx1 - 1] == t[idx2 - 1]:
                    current[idx2] = take + notTake
                else:
                    current[idx2] = notTake
            dp = current
        return dp[n2]