class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        start, end, pos = 0, len(nums) - 1, 0
        while start <= end:
            mid = start + (end - start) // 2
            if nums[mid] == target: 
                return mid
            elif nums[mid] < target:
                pos = mid + 1
                start = mid + 1
            else:
                end = mid - 1
        return pos