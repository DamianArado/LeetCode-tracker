class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        ans = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]: 
                nums[ans] = nums[i] 
                ans += 1
        return ans