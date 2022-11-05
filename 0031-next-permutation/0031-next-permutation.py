class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        if n == 1: return
        
        suffixStart = n - 1
        while suffixStart > 0 and nums[suffixStart - 1] >= nums[suffixStart]:
            suffixStart -= 1
        if suffixStart == 0 and nums[suffixStart] >= nums[suffixStart + 1]:
            nums[ : ] = nums[ : : -1]
        else:
            pivot, rightmostGreater = suffixStart - 1, n - 1
            while nums[pivot] >= nums[rightmostGreater]:
                rightmostGreater -= 1
            nums[pivot], nums[rightmostGreater] = nums[rightmostGreater], nums[pivot]
            nums[suffixStart : ] = nums[n - 1 : suffixStart - 1 : -1]
        