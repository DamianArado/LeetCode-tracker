class Solution:
    
    def findLCS(self, s: str, reverse: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            current = [0] * (n + 1)
            for j in range(1, n + 1):
                # match
                if s[i - 1] == reverse[j - 1]:
                    current[j] = 1 + dp[j - 1]
                else:
                    current[j] = max(dp[j], current[j - 1])
            dp = current
        return dp[n]
            
    def longestPalindromeSubseq(self, s: str) -> int:
        # using slicing to reverse a string
        reverse = s[::-1]
        return self.findLCS(s, reverse)