class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        count = [0] * (201)
        result = 0
        for num in nums:
            if num >= 2 * diff:
                if count[num - diff] and count[num - 2 * diff]:
                    result += 1
            count[num] = 1
        return result