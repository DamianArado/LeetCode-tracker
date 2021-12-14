class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;
        
        int n = nums.size();
        
        // check if 0th/n-1th index is the peak element
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        
        // check for remaining elements
        int low = 1, high = nums.size() - 2;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if(nums[mid] < nums[mid - 1])
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return -1;
    }
};