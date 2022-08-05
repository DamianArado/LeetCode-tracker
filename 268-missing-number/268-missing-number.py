class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n, apparentSum = len(nums), 0
        realSum = n * (n + 1) // 2
        for num in nums: apparentSum += num
        return realSum - apparentSum