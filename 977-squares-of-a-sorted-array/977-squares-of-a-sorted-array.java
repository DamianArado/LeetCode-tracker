class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int i = 0, j = n - 1;
        for(int ptr = n - 1; ptr >= 0; --ptr) {
            if(Math.abs(nums[j]) > Math.abs(nums[i])) {
                ans[ptr] = nums[j] * nums[j];
                --j;
            } else {
                ans[ptr] = nums[i] * nums[i];
                ++i;
            }
        }
        return ans;
    }
}