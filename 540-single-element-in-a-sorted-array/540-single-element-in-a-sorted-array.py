class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return nums[0]
        
        start, end = 0, n - 2
        while start <= end:
            mid = start + (end - start) // 2
            # If we are on left side, move right
            if nums[mid] == nums[mid ^ 1]: 
                start = mid + 1
                # If we are on right side, move left
            else:
                end = mid - 1
                
        return nums[start]