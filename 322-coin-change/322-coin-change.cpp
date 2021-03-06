/**

Approach 1: Recurrence that we will use for this infinite supply based problem

f(index, target):
    if(index == 0):
        if(target % coins[0] == 0): 
            return target / coins[0]
        else:
            return 1e8
    notTake = f(index - 1, target)
    take = INT_MAX
    if(coins[index] <= target):
        take = 1 + f(index, target - coins[index])
    return min(take, notTake)

TC: exponential, SC: O(target)

Approach 2: Using memoization (avoid repeated computation of the same problem) over recursion

class Solution {
private:
    int f(int index, int amount, vector<int>& coins, vector<vector<int>> &dp) {
        if(index == 0) {
            if(amount % coins[0] == 0) return amount / coins[index];
            else return 1e9;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int take = 1e9;
        int notTake = f(index - 1, amount, coins, dp);
        if(coins[index] <= amount)
            take = 1 + f(index, amount - coins[index], coins, dp);  // infinite supply so we keep standing on this index
        return dp[index][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        return ans < 1e9 ? ans : -1;
    }
};

TC: O(n*amount), SC: O(n*amount + amount)

Approach 3: Using tabulation

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for(int i = 0; i <= amount; ++i)
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9;
        for(int index = 1; index < n; ++index) {
            for(int target = 0; target <= amount; ++target) {
                int take = 1e9;
                int notTake = dp[index - 1][target];
                if(coins[index] <= target)
                    take = 1 + dp[index][target - coins[index]];
                dp[index][target] = min(take, notTake);
            }
        }
        return (dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount]);
    }
};

TC & SC: O(n*amount)

*/

class Solution {
public:
    // TC: O(n*amount), SC: O(amount)
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        for(int i = 0; i <= amount; ++i)
            if(i % coins[0] == 0) dp[i] = i / coins[0];
            else dp[i] = 1e9;
        for(int index = 1; index < n; ++index) {
            vector<int> current(amount + 1, 0);
            for(int target = 0; target <= amount; ++target) {
                int take = 1e9;
                int notTake = dp[target];
                if(coins[index] <= target)
                    // VERY IMPORTANT: since you don't move to the previous index, use current
                    take = 1 + current[target - coins[index]];
                current[target] = min(take, notTake);
            }
            dp = current;
        }
        return (dp[amount] == 1e9 ? -1 : dp[amount]);
    }
};