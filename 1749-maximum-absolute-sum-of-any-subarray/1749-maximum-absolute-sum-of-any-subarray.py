class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        sums, maxSum, minSum = 0, 0, 0
        for num in nums:
            sums += num
            maxSum = max(maxSum, sums)
            minSum = min(minSum, sums)
        return maxSum - minSum