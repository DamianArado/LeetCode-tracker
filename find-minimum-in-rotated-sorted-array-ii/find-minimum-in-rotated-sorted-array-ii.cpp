/*

nums[low] <= nums[mid] <= nums[high], min is nums[low]
nums[low] > nums[mid] <= nums[high], (low, mid] is not sorted, min is inside
nums[low] <= nums[mid] > nums[high], (mid, high] is not sorted, min is inside
nums[low] > nums[mid] > nums[high]

*/
class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            } else if(nums[mid] < nums[low]) {
                high = mid;
                ++low;
            } else {
                --high;  // nums[low] <= nums[mid] <= nums[high]
            }
        }        
        return nums[low];
    }
};