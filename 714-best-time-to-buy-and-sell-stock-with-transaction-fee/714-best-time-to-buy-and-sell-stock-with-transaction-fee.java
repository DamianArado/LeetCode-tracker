class Solution {
    public int maxProfit(int[] prices, int fee) {
        int[] dp = new int[2];
        for(int index = prices.length - 1; index >= 0; --index) {
            int[] current = new int[2];
            current[1] = Math.max(-prices[index] + dp[0], dp[1]);
            current[0] = Math.max(prices[index] + dp[1] - fee, dp[0]);
            dp = current;
        }
        return dp[1];
    }
}