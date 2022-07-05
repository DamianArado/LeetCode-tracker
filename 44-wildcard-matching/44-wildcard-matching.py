class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n1 = len(s)
        n2 = len(p)
        dp = [False] * (n2 + 1)
        dp[0] = True
        for idx2 in range (1, n2 + 1):
            allAsterisks = True
            for i in range (1, idx2 + 1):
                if p[i - 1] != '*':
                    allAsterisks = False
                    break
            dp[idx2] = allAsterisks
        for idx1 in range (1, n1 + 1):
            current = [False] * (n2 + 1)
            for idx2 in range (1, n2 + 1):
                if s[idx1 - 1] == p[idx2 - 1] or p[idx2 - 1] == '?':
                    current[idx2] = dp[idx2 - 1]
                elif p[idx2 - 1] == '*':
                    consider = dp[idx2]
                    notConsider = current[idx2 - 1]
                    current[idx2] = consider or notConsider
                else:
                    current[idx2] = False
            dp = current
        return dp[n2]
                    