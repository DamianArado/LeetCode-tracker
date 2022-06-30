class Solution {
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[] dp = new int[amount + 1];
        for(int i = 0; i <= amount; ++i) 
            if(i % coins[0] == 0) dp[i] = i / coins[0];
            else dp[i] = (int) 1e9;
        for(int index = 1; index < n; ++index) {
            int[] current = new int[amount + 1];
            for(int target = 0; target <= amount; ++target) {
                int take = (int) 1e9;
                int notTake = dp[target];
                if(coins[index] <= target)
                    take = 1 + current[target - coins[index]];
                current[target] = Math.min(take, notTake);
            }
            dp = current;
        }
        return (dp[amount] == 1e9 ? -1 : dp[amount]);
    }
}