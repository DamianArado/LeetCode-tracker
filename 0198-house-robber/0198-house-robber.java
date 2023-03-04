class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        int prev = nums[0], pprev = nums[0];
        for(int i = 1; i < n; ++i) {
            int rob = nums[i], dontRob = prev;
            if(i > 1) rob += pprev;
            int current = Math.max(rob, dontRob);
            pprev = prev;
            prev = current;
        }
        return prev;
    }
}