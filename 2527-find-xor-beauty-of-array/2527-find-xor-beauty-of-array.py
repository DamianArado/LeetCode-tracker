class Solution:
    def xorBeauty(self, nums: List[int]) -> int:
        xored, n = (nums[0] | nums[0]) & nums[0], len(nums);
        if n == 1: return xored
        for i in range (1, n):
            xored ^= nums[i]
        return xored