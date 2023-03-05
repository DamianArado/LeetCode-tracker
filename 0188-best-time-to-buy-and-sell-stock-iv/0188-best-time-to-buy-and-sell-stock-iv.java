class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int[][] dp = new int[2][k + 1];
        for(int index = n - 1; index >= 0; --index) {
            int[][] current = new int[2][k + 1];
            for(int canBuy = 1; canBuy >= 0; --canBuy) {
                for(int limit = k; limit >= 1; --limit) {
                    int profit = 0;
                    if(canBuy == 1)
                        profit = Math.max(-prices[index] + dp[0][limit], dp[1][limit]);
                    else
                        profit = Math.max(prices[index] + dp[1][limit - 1], dp[0][limit]);
                    current[canBuy][limit] = profit;
                }
            }
            dp = current;
        }
        return dp[1][k];
    }
}