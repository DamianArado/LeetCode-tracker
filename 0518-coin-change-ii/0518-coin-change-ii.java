class Solution {
    public int change(int amount, int[] coins) {
        int n = coins.length;
        int[] dp = new int[amount + 1];
        for (int i = 0; i <= amount; ++i) 
            if (i % coins[0] == 0)
                dp[i] = 1;
        for (int index = 1; index < n; ++index) {
            int[] current = new int[amount + 1];
            for (int target = 0; target <= amount; ++target) {
                int take = 0;
                int notTake = dp[target];
                if (coins[index] <= target)
                    take = current[target - coins[index]];
                current[target] = take + notTake;
            }
            dp = current;
        }
        return dp[amount];
    }
}