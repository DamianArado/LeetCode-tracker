/**

Approach 1: Using recursion - O(2^n) TC & O(n) SC

class Solution {
private:
    int f(int index, int canBuy, int limit, vector<int> &prices) {
        // base case: if we reached the end OR if the limit exhausted
        if(index == prices.size() or limit == 0)
            return 0;
        int profit = 0;
        if(canBuy) 
            profit = max(-prices[index] + f(index + 1, 0, limit, prices), 0 + f(index + 1, 1, limit, prices));
        else 
            profit = max(prices[index] + f(index + 1, 1, limit - 1, prices), 0 + f(index + 1, 0, limit, prices));
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        return f(0, 1, 2, prices);
    }
};

Approach 2: Using memoization over recursion - O(n*2*3) TC & O(n*2*3 + n) SC

class Solution {
private:
    int f(int index, int canBuy, int limit, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        // base case: if we reached the end OR if the limit exhausted
        if(index == prices.size() or limit == 0)
            return 0;
        if(dp[index][canBuy][limit] != -1) return dp[index][canBuy][limit];
        int profit = 0;
        if(canBuy) 
            profit = max(-prices[index] + f(index + 1, 0, limit, prices, dp), f(index + 1, 1, limit, prices, dp));
        else 
            profit = max(prices[index] + f(index + 1, 1, limit - 1, prices, dp), f(index + 1, 0, limit, prices, dp));
        return dp[index][canBuy][limit] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return f(0, 1, 2, prices, dp);
    }
}; 

Approach 3: Using tabulation - O(n*2*2) TC & O(n*2*3) SC

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n + 1][2][3];
        memset(dp, 0, sizeof(dp));
        for(int index = n - 1; index >= 0; --index) {
            for(int canBuy = 1; canBuy >= 0; --canBuy) {
                // limit goes from 2 -> 1 and not 0 due to [limit - 1] index
                for(int limit = 2; limit >= 1; --limit) {
                    int profit = 0;
                    if(canBuy)
                        profit = max(-prices[index] + dp[index + 1][0][limit], 0 + dp[index + 1][1][limit]);
                    else 
                        profit = max(prices[index] + dp[index + 1][1][limit - 1], 0 + dp[index + 1][0][limit]);
                    dp[index][canBuy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};