class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = nums[0];
        for(int i = 1; i < n; ++i) {
            int rob = nums[i], dontRob = dp[i - 1];
            if(i > 1) rob += dp[i - 2];
            dp[i] = Math.max(rob, dontRob);
        }
        return dp[n - 1];
    }
}