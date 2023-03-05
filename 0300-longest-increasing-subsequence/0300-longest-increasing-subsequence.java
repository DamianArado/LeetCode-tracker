class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length, maxLIS = 1;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for(int i = 0; i < n; ++i) {
            for(int left = 0; left < i; ++left)
                if(nums[left] < nums[i])
                    dp[i] = Math.max(dp[i], 1 + dp[left]);
            maxLIS = Math.max(maxLIS, dp[i]);
        }
        return maxLIS;
    }
}