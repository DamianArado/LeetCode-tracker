class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        i, j = 0, n - 1
        for ptr in range (n - 1, -1, -1):
            if abs(nums[j]) > abs(nums[i]):
                ans[ptr] = nums[j] * nums[j]
                j -= 1
            else:
                ans[ptr] = nums[i] * nums[i]
                i += 1
        return ans