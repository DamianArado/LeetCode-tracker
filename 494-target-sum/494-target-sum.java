// by far one of the most evil test cases :''D
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int sum = 0, n = nums.length;
        for(int num : nums)
            sum += num;
        if((sum - target < 0) | (sum - target) % 2 == 1)
            return 0;
        int k = (sum - target) / 2;
        int[] dp = new int[k + 1];
        dp[0] = 1;
        for(int idx = 1; idx <= n; ++idx) {
            int[] current = new int[k + 1];
            for(int trgt = 0; trgt <= k; ++trgt) {
                int taken = 0;
                int notTaken = dp[trgt];
                if(nums[idx - 1] <= trgt)
                    taken = dp[trgt - nums[idx - 1]];
                current[trgt] = taken + notTaken;
            }
            dp = current;
        }
        return dp[k];
    }
}