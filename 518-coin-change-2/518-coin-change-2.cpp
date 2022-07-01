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
    
Approach 1: Memoization over recursion - O(n*T) TC & O(n*T + T) SC



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

*/
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