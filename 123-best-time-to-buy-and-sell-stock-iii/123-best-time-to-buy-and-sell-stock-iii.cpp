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

Approach 2: Using memoization over recursion - O(n*2*2) TC & O(n*2*2 + n) SC


*/
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