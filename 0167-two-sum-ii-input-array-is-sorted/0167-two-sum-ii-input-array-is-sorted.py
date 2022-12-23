class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        i, j = 0, n - 1
        ans = [0, 0]
        while i < j:
            sums = nums[i] + nums[j]
            if sums == target: 
                ans[0] = i + 1
                ans[1] = j + 1
                return ans
            elif sums > target: 
                j -= 1
            else:
                i += 1
        return ans