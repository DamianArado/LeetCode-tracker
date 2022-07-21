class Solution {
public:
    int search(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(target == nums[mid]) return mid;
            // If we check in a part where we see rotation
            // We start searching in the sorted region if our target lies in that range
            if(nums[start] > nums[mid]) {
                if(target > nums[mid] and target <= nums[end])
                    start = mid + 1;
                else end = mid - 1;
            } else if(nums[mid] > nums[end]) {
                if(target >= nums[start] and target < nums[mid])
                    end = mid - 1;
                else start = mid + 1;
            // If we enter the sorted region
            } else {
                if(target > nums[mid]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};