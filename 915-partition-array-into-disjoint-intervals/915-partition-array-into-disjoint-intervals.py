class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        maxUntilNow, leftPartMax, partIdx = nums[0], nums[0], 0
        for i in range (len(nums)):
            maxUntilNow = max(maxUntilNow, nums[i])
            if nums[i] < leftPartMax:
                leftPartMax, partIdx = maxUntilNow, i
        return partIdx + 1
                