class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        int start = 0, end = n - 2; 
        while(start <= end){
            int mid = start + (end - start) / 2;
			// If we are on left side, move right
            if(nums[mid] == nums[mid ^ 1]) start = mid + 1;
			// if we are on right side, move left
            else end = mid - 1;
        }
        return nums[start];
    }
}