class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length, maxLIS = 0, numLIS = 0;
        if(n == 1) return 1;
        int[] dp = new int[n];
        int[] count = new int[n];
        for(int i = 0; i < n; ++i) {
            dp[i] = 1;
            count[i] = 1;
        }
        for(int i = 1; i < n; ++i) {
            for(int prev = 0; prev < i; ++prev) {
                if(nums[prev] < nums[i] && dp[prev] + 1 > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    count[i] = count[prev];
                } else if(nums[prev] < nums[i] && dp[prev] + 1 == dp[i])
                    count[i] += count[prev];
            }
            maxLIS = Math.max(maxLIS, dp[i]);
        }
        for(int i = 0; i < n; ++i) 
            if(dp[i] == maxLIS)
                numLIS += count[i];
        return numLIS;
    }
}