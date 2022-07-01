/**

Recurrence - O(exponential) TC & O(amount) SC

f(index, amount):
    if(index == 0):
        return (amount % coins[0] == 0)
    take = 0
    notTake = f(index - 1, amount)
    if(coins[index] <= amount):
        take = f(index, amount - coins[index])
    return take + notTake
    
Approach 1: Memoization over recursion - O(n*amount) TC & O(n*amount + amount) SC

class Solution {
private:
    int f(int index, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if(index == 0)
            return (amount % coins[0] == 0);
        if(dp[index][amount] != -1)
            return dp[index][amount];
        int take = 0;
        int notTake = f(index - 1, amount, coins, dp);
        if(coins[index] <= amount)
            take = f(index, amount - coins[index], coins, dp);
        return dp[index][amount] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (auto coin : coins)
            for (int i=1; i<=amount; i++)
                if (coin <= i) dp[i] += dp[i-coin];
        return dp[amount];
    }
};

Approach 2: Tabulation - O(n*amount) TC & SC

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        // base case
        for(int i = 0; i <= amount; ++i)
            if(i % coins[0] == 0) 
                dp[0][i] = 1;
        for(int index = 1; index < n; ++index) {
            for(int target = 0; target <= amount; ++target) {
                int take = 0;
                int notTake = dp[index - 1][target];
                if(coins[index] <= target)
                    take = dp[index][target - coins[index]];
                dp[index][target] = take + notTake;
            }
        }
        return dp[n - 1][amount];
    }
};

Approach 3: Using space optimization over tabulation - O(n*amount) TC & O(amount) SC



*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp (amount + 1, 0);
        // base case
        for(int i = 0; i <= amount; ++i)
            if(i % coins[0] == 0) 
                dp[i] = 1;
        for(int index = 1; index < n; ++index) {
            vector<int> current (amount + 1, 0);
            for(int target = 0; target <= amount; ++target) {
                int take = 0;
                int notTake = dp[target];
                if(coins[index] <= target)
                    take = current[target - coins[index]];
                current[target] = take + notTake;
            }
            dp = current;
        }
        return dp[amount];
    }
};