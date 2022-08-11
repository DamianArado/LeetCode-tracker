class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        triplets = []
        n = len(nums)
        nums = sorted(nums)
        for i in range(n - 2):
            if nums[i] > 0: return triplets
            if i == 0 or (i > 0 and nums[i] != nums[i - 1]):
                j, k, reqSum = i + 1, n - 1, -nums[i]
                while j < k:
                    if nums[j] + nums[k] == reqSum:
                        triplets.append([nums[i], nums[j], nums[k]])
                        while j < k and nums[j] == nums[j + 1]: j += 1
                        while j < k and nums[k] == nums[k - 1]: k -= 1
                        j += 1
                        k -= 1
                    elif nums[j] + nums[k] > reqSum: k -= 1
                    else: j += 1
        return triplets