class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, n = nums.size(), end = n - 1;
        // the only edge case
        if(n == 1) return nums[0];
        while(start <= end) {
            if(nums[start] < nums[end]) return nums[start];
            int mid = start + (end - start) / 2;
            // preferrable to initialize like this to save us from index out of bound
            int prev = (mid + n - 1) % n, next = (mid + 1) % n;
            // if found the smallest element
            if(nums[mid] < nums[prev] and nums[mid] < nums[next]) return nums[mid];
            // move to the unsorted region
            if(nums[start] <= nums[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return nums[start];
    }
};