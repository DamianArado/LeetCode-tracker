class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        cntPlus = cntNeg = 0
        for num in nums:
            if num < 0: cntNeg += 1
            elif num > 0: cntPlus += 1
        return max(cntPlus, cntNeg)