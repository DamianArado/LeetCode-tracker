class Solution {
    public int findMin(int[] nums) {
        int start = 0, n = nums.length;
        int end = n - 1;
        while(start <= end) {
            if(nums[start] <= nums[end]) return nums[start];
            int mid = start + (end - start) / 2;
            int prev = (mid + n - 1) % n, next = (mid + 1) % n;
            // found 
            if(nums[mid] < nums[prev] && nums[mid] < nums[next]) return nums[mid];
            // else search in the unsorted portion
            if(nums[start] <= nums[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return nums[end];
    }
}