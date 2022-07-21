class Solution:
    def findMin(self, nums: List[int]) -> int:
        start = 0
        n = len(nums)
        end = n - 1
        
        while start <= end:
            if nums[start] <= nums[end]:
                return nums[start]
            mid = start + (int)((end - start) / 2)
            prev = (mid + n - 1) % n
            nextt = (mid + 1) % n
            if nums[mid] < nums[prev] and nums[mid] < nums[nextt]:
                return nums[mid]
            if nums[start] <= nums[mid]:
                start = mid + 1
            else:
                end = mid - 1
        return nums[start]