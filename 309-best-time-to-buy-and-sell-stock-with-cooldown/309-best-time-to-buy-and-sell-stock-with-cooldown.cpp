/**

Approach 1: Memoization using recursion - O(n*2) TC & O(n*2 + n) SC

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

Approach 2: Using tabulation - O(n*2) TC & SC

*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n + 2][2];
        memset(dp, 0, sizeof(dp));
        for(int index = n - 1; index >= 0; --index) {
            for(int canBuy = 1; canBuy >= 0; --canBuy) {
                int profit = 0;
                if(canBuy)
                    profit = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
                else
                    profit = max(prices[index] + dp[index + 2][1], dp[index + 1][0]);
                dp[index][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
};