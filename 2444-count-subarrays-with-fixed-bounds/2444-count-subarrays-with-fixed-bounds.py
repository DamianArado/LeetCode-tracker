class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        count, lastMinIdx, lastMaxIdx, subarrStartIdx = 0, -1, -1, 0
        for i in range (0, len(nums)):
            if nums[i] < minK or nums[i] > maxK:
                lastMinIdx, lastMaxIdx, subarrStartIdx = -1, -1, i + 1
            if nums[i] == minK:
                lastMinIdx = i
            if nums[i] == maxK:
                lastMaxIdx = i
            count += max(0, min(lastMinIdx, lastMaxIdx) - subarrStartIdx + 1)
        return count