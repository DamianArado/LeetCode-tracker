class Solution {
    public int findPeakElement(int[] nums) {
        // here we will use the concept of binary search on unsorted arrays
        int n = nums.length;
        
        // edge case + checking for the corner elements
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n - 1] > nums[n - 2]) return n - 1;
        
        // now we will check for the remaining elements
        int start = 1, end = n - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            // else move towards more promising region
            else if(nums[mid + 1] > nums[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
}