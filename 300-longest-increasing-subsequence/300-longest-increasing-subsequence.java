class Solution {
    private int f(int index, int previous, int[] nums, int[][] dp) {
        if(index == nums.length) return 0;
        
        if(dp[index][previous + 1] != -1) return dp[index][previous + 1];
        
        int take = 0, notTake = 0;
        if(previous == -1 || nums[index] > nums[previous])
            take = 1 + f(index + 1, index, nums, dp);
        notTake = f(index + 1, previous, nums, dp);
        
        return dp[index][previous + 1] = Math.max(take, notTake);
    }
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][n + 1];
        for(int[] row : dp) Arrays.fill(row, -1);
        return f(0, -1, nums, dp);
    }
}