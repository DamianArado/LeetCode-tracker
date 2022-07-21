class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums) - 1
        
        while start <= end:
            mid = start + (int)((end - start) / 2);
            # check if we reached the target
            if nums[mid] == target: 
                return mid
            # check if we are under a rotated array
            if nums[mid] < nums[start]:
                # search in sorted half
                if target > nums[mid] and target <= nums[end]:
                    start = mid + 1
                else:
                    end = mid - 1
            elif nums[end] < nums[mid]:
                # repeat like the above
                if target >= nums[start] and target < nums[mid]:
                    end = mid - 1
                else:
                    start = mid + 1
            else:
                # [start, end] is sorted
                if target > nums[mid]:
                    start = mid + 1
                else:
                    end = mid - 1
        return -1