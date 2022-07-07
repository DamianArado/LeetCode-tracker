class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int> (k + 1, 0));
        for(int index = prices.size() - 1; index >= 0; --index) {
            vector<vector<int>> current(2, vector<int> (k + 1, 0));
            for(int canBuy = 1; canBuy >= 0; --canBuy) {
                for(int limit = k; limit >= 1; --limit) {
                    int profit = 0;
                    if(canBuy)
                        profit = max(-prices[index] + dp[0][limit], dp[1][limit]);
                    else
                        profit = max(prices[index] + dp[1][limit - 1], dp[0][limit]);
                    current[canBuy][limit] = profit;
                }
            }
            dp = current;
        }
        return dp[1][k];
    }
};