class Solution {
private:
    int f(int idx, int canBuy, vector<int>& prices, vector<vector<int>> &dp, int n) {
        if(idx > n - 1) return 0;
        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        int profit = 0;
        if(canBuy)
            profit = max(-prices[idx] + f(idx + 1, 0, prices, dp, n), f(idx + 1, 1, prices, dp, n));
        else
            profit = max(prices[idx] + f(idx + 2, 1, prices, dp, n), f(idx + 1, 0, prices, dp, n));
        return dp[idx][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, dp, n);
    }
};