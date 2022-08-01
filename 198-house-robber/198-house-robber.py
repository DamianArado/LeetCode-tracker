class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        prev2, prev = 0, nums[0]
        for idx in range (1, n):
            current = max(nums[idx] + prev2, prev)
            prev2 = prev
            prev = current
        return prev