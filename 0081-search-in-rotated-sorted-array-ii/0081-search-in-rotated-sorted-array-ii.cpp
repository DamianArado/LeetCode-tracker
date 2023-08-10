class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = size(nums) - 1;
        if (size(nums) == 1) return nums[0] == target;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) return true;
            // Check for duplicates
            if (nums[start] == nums[mid] and nums[end] == nums[mid]) {
               ++start; --end;
            }
            // if first half is in order, target is in first half
            else if (nums[start] <= nums[mid]) {
                if (nums[start] <= target and nums[mid] > target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
			// if second half is order, target is in second half
            else {
                if (nums[mid] < target and target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};