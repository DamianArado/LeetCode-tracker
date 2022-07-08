/*

Approach 1: Using tabulation - O(n) TC & O(2*n) SC

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[n + 2][2];
        memset(dp, 0, sizeof(dp));
        for(int index = n - 1; index >= 0; --index) {
            dp[index][1] = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
            dp[index][0] = max(prices[index] + dp[index + 1][1] - fee, dp[index + 1][0]);
        }
        return dp[0][1];
    }
};

Approach 2: Using space optimization over tabulation - O(n) TC & O(1) SC
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(2, 0), current(2, 0);
        for(int index = n - 1; index >= 0; --index) {
            current[1] = max(-prices[index] + dp[0], dp[1]);
            current[0] = max(prices[index] + dp[1] - fee, dp[0]);
            dp = current;
        }
        return dp[1];
    }
};