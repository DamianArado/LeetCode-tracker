class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        k, i, j = 1, 0, 0
        for j in range (len(nums)):
            if nums[j] == 0: 
                k -= 1
            if k < 0 and nums[i] == 1:
                i += 1
            elif k < 0 and nums[i] == 0:
                i += 1
                k += 1
        return j - i