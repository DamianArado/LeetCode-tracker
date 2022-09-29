class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = size(nums);
        if(n == 1) return nums[0];
        if(n == 2) return min(nums[0], nums[1]);
        
        int start = 0, end = n - 1;
        while(start <= end) {
            if(nums[start] < nums[end]) return nums[start];
            int mid = start + (end - start) / 2;
            
            if(nums[mid] > nums[end]) 
                start = mid + 1;
            else if(nums[mid] < nums[start]) {
                end = mid;
                ++start;
            }
            else --end;
        }
        return nums[start];
    }
};