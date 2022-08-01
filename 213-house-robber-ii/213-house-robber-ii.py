class Solution:
    def maxRob(self, nums: List[int], start: int, end: int) -> int:
        prev2, prev = 0, nums[start]
        for idx in range(start + 1, end + 1):
            current = max(nums[idx] + prev2, prev)
            prev2 = prev
            prev = current
        return prev
        
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return nums[0]
        return max(self.maxRob(nums, 0, n - 2), self.maxRob(nums, 1, n - 1))