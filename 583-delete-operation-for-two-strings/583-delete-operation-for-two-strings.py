class Solution:
    def findLCS(self, word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)
        maxLen = 0
        dp = [0] * (n + 1)
        for i in range(1, m + 1):
            current = [0] * (n + 1)
            for j in range(1, n + 1):
                # match
                if word1[i - 1] == word2[j - 1]:
                    current[j] = 1 + dp[j - 1]
                else:
                    current[j] = max(dp[j], current[j - 1])
            dp = current
        return dp[n]
    
    def minDistance(self, word1: str, word2: str) -> int:
        return len(word1) + len(word2) - 2 * self.findLCS(word1, word2)