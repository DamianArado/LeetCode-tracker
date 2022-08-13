class Solution:
    def minimumAbsDifference(self, nums: List[int]) -> List[List[int]]:
        n, minDiff = len(nums), 1e7
        minDiffPairs = []
        nums = sorted(nums)
        
        for i in range (1, n):
            minDiff = min(minDiff, nums[i] - nums[i - 1])
        
        for i in range (1, n):
            if nums[i] - nums[i - 1] == minDiff:
                minDiffPairs.append([nums[i - 1], nums[i]])
        
        return minDiffPairs;