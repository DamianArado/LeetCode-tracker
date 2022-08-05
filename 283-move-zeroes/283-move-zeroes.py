class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        zeroes, n = 0, len(nums)
        for num in nums:
            if num == 0: zeroes += 1
        nonZeroes, eIdx =  n - zeroes, 0
        for i in range(n): 
            if nums[i] != 0: 
                nums[eIdx] = nums[i]
                eIdx += 1
        while eIdx < n:
            nums[eIdx] = 0
            eIdx += 1
        