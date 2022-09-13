class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length, maxLIS = 1;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for(int idx = 1; idx < n; ++idx) {
            for(int prev = 0; prev < idx; ++prev)
                if(nums[prev] < nums[idx])
                    dp[idx] = Math.max(dp[idx], 1 + dp[prev]);
            maxLIS = Math.max(maxLIS, dp[idx]);
        }
        return maxLIS;
    }
}