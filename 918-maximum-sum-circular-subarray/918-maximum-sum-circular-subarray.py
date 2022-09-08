class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        total, curMax, curMin, maxSum, minSum = 0, 0, 0, nums[0], nums[0]
        for num in nums:
            total += num
            curMax = max(curMax + num, num)
            maxSum = max(maxSum, curMax)
            curMin = min(curMin + num, num)
            minSum = min(minSum, curMin)
        return maxSum if maxSum < 0 else max(maxSum, total - minSum)