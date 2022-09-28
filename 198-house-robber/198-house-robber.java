class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        int pprev = nums[0], prev = Math.max(nums[0], nums[1]);
        
        for(int i = 2; i < n; ++i) {
            int current = Math.max(nums[i] + pprev, prev);
            pprev = prev;
            prev = current;
        }
        
        return prev;
    }
}