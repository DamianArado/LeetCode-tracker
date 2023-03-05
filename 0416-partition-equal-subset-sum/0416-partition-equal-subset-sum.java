class Solution {
    private boolean subsetSumEqualsK(int[] nums, int k) {
        boolean[] dp = new boolean[k + 1];
        dp[0] = true;
        if(nums[0] <= k) dp[nums[0]] = true;
        for(int index = 1; index < nums.length; ++index) {
            boolean[] current = new boolean[k + 1];
            current[0] = true;
            for(int target = 1; target <= k; ++target) {
                boolean notTake = dp[target];
                boolean take = false;
                if(nums[index] <= target)
                    take = dp[target - nums[index]];
                current[target] = take | notTake;
            }
            dp = current;
        }
        return dp[k];
    }
    public boolean canPartition(int[] nums) {
        int totalSum = 0;
        for(int num : nums)
            totalSum += num;
        if(totalSum % 2 == 1) return false;
        int target = totalSum / 2;
        return subsetSumEqualsK(nums, target);
    }
}