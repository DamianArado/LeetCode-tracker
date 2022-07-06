/**

Approach 1: Using Recursion - O(2^n) TC & O(n)

class Solution {
private:
    int f(int index, int canBuy, vector<int>& prices, int n) {
        if(index == n) return 0;
        int profit = 0;
        if(canBuy) 
            profit = max(-prices[index] + f(index + 1, 0, prices, n), 0 + f(index + 1, 1, prices, n));
        else
            profit = max(0 + f(index + 1, 0, prices, n), prices[index] + f(index + 1, 1, prices, n));
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        return f(0, 1, prices, prices.size());    
    }
};

Approach 2: Using memoization over recursion - O(n*2) TC & O(n*2 + n) SC

class Solution {
private:
    int f(int index, int canBuy, vector<int>& prices, int n, vector<vector<int>> &dp) {
        if(index == n) return 0;
        if(dp[index][canBuy] != -1) return dp[index][canBuy];
        int profit = 0;
        if(canBuy) 
            // max (buy a stock today, didn't buy a stock today)
            profit = max(-prices[index] + f(index + 1, 0, prices, n, dp), 0 + f(index + 1, 1, prices, n, dp));
        else
            // max (sell a stock today, didn't sell a stock today)
            profit = max(0 + f(index + 1, 0, prices, n, dp), prices[index] + f(index + 1, 1, prices, n, dp));
        return dp[index][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, n, dp);    
    }
};

Approach 3: Using tabulation - O(n*2) TC & SC

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        for(int index = n - 1; index >= 0; --index) {
            for(int canBuy = 1; canBuy >= 0; --canBuy) {
                int profit = 0;
                if(canBuy)
                    // max (buy a stock today, didn't buy a stock today)
                    profit = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
                else
                    // max (sell a stock today, didn't sell a stock today)
                    profit = max(prices[index] + dp[index + 1][1], 0 + dp[index + 1][0]);
                dp[index][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
};

Approach 4: Using space optimization over tabulation - O(n*2) TC & O(4) SC

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp (2, 0);
        for(int index = n - 1; index >= 0; --index) {
            vector<int> current (2, 0);
            for(int canBuy = 1; canBuy >= 0; --canBuy) {
                int profit = 0;
                if(canBuy)
                    // max (buy a stock today, didn't buy a stock today)
                    profit = max(-prices[index] + dp[0], 0 + dp[1]);
                else
                    // max (sell a stock today, didn't sell a stock today)
                    profit = max(prices[index] + dp[1], 0 + dp[0]);
                current[canBuy] = profit;
            }
            dp = current;
        }
        return dp[1];
    }
};

Approach 5: One pass accumulation of profit using adjacent elements - O(n) TC & O(1) SC

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i)
            profit += max(prices[i] - prices[i - 1], 0);
        return profit;
    }
};