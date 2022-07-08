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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n + 2][2];
        int current[n + 2][2];
        memset(dp, 0, sizeof(dp));
        memset(current, 0, sizeof(current));
        for(int index = n - 1; index >= 0; --index) {
            dp[index][1] = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
            dp[index][0] = max(prices[index] + dp[index + 2][1], dp[index + 1][0]);
        }
        return dp[0][1];
    }
};

Approach 3: Space optimize using 3 columns of size 2 - O(n*2) TC & O(2*2*2) -> O(1) SC



*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        /*
        
                        n + 1           n               n - 1       n - 2
        i = n - 1       previous2       previous1       current
        i = n - 2                       previous2       previous1   current
        
        */
        vector<int> previous2(2, 0);        
        vector<int> previous1(2, 0);
        vector<int> current(2, 0);
        for(int index = n - 1; index >= 0; --index) {
            current[1] = max(-prices[index] + previous1[0], previous1[1]);
            current[0] = max(prices[index] + previous2[1], previous1[0]);
            previous2 = previous1;
            previous1 = current;
        }
        return current[1];
    }
};