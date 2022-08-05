class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        singleOne = 0
        for num in nums: singleOne ^= num
        return singleOne