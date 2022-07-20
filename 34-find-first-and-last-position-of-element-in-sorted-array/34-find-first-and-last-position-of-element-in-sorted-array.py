class Solution:
    def findUpperBound(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums) - 1
        while start <= end: 
            mid = start + (int)((end - start) / 2)
            if nums[mid] >= target:
                end = mid - 1
            else: start = mid + 1
        return start
    def findLowerBound(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums) - 1
        while start <= end: 
            mid = start + (int)((end - start) / 2)
            if nums[mid] <= target:
                start = mid + 1
            else: end = mid - 1
        return start
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        startIdx = self.findUpperBound(nums, target)
        endIdx = self.findLowerBound(nums, target)
        if startIdx == endIdx: return [-1, -1]
        else: return [startIdx, endIdx - 1]