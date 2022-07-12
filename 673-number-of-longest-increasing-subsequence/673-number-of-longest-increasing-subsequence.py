class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        maxLIS = 0
        numLIS = 0
        
        if n == 1: 
            return 1
        
        dp = [1] * (n)
        count = [1] * (n)
        
        for i in range (1, n):
            for prev in range (0, i):
                if nums[prev] < nums[i] and dp[prev] + 1 > dp[i]:
                    dp[i] = 1 + dp[prev]
                    count[i] = count[prev]
                elif nums[prev] < nums[i] and dp[prev] + 1 == dp[i]:
                    count[i] += count[prev]
            maxLIS = max(maxLIS, dp[i])
        
        for i in range (n):
            if dp[i] == maxLIS:
                numLIS += count[i]
        return numLIS