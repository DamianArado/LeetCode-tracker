class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1 = len(word1)
        n2 = len(word2)
        dp = [0] * (n2 + 1);
        for idx2 in range (1, n2 + 1):
            dp[idx2] = idx2
        for idx1 in range (1, n1 + 1):
            current = [0] * (n2 + 1)
            current[0] = idx1
            for idx2 in range (1, n2 + 1):
                if word1[idx1 - 1] == word2[idx2 - 1]:
                    current[idx2] = dp[idx2 - 1]
                else:
                    insert = current[idx2 - 1]
                    delete = dp[idx2]
                    replace = dp[idx2 - 1]
                    current[idx2] = 1 + min(insert, delete, replace)
            dp = current
        return dp[n2]