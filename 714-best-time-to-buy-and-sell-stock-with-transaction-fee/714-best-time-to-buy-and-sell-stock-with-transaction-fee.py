class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        dp = [0, 0]
        for i in range (len(prices) - 1, -1, -1):
            current = [0, 0]
            current[1] = max(-prices[i] + dp[0], dp[1])
            current[0] = max(prices[i] + dp[1] - fee, dp[0])
            dp = current
        return dp[1]
        