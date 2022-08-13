class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        i = j = 0
        for j in range (0, len(nums)):
            if nums[j] == 0: k -= 1
            if k < 0 and nums[i] == 1: 
                i += 1
            elif k < 0 and nums[i] == 0: 
                i += 1
                k += 1
        return j - i + 1