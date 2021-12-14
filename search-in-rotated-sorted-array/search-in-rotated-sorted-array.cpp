class Solution {
public:
    int findMinIdx(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    
    int search(vector<int> &nums, int target) {
        int minIdx = findMinIdx(nums);
        
        if (target == nums[minIdx]) return minIdx;
        
        int n = nums.size();
        
        int low = (target <= nums[n - 1]) ? minIdx : 0;
        int high = (target > nums[n - 1]) ? minIdx : n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};