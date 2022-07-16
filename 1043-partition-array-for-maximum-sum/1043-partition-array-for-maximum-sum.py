class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        dp = [0] * (n + 1)
        for start in range (n - 1, -1, -1):
            length = 0
            maxNum = -1
            maxSum = 0
            for end in range (start, min(n, start + k)):
                maxNum = max(maxNum, arr[end])
                length += 1
                maxSum = max(maxSum, maxNum * length + dp[end + 1])
            dp[start] = maxSum
        return dp[0]