/*

Problem Statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and the ith item weighs wi and is of value vi. 
Considering the constraints of the maximum weight that a knapsack can carry, 
you have to find and return the maximum value that a thief can generate by stealing items.

w[i] = [3,4,6]
v[i] = [40,50,70]
W = 8
O/P: 90

*/

Basic recurrence - O(2^n) TC and O(n) SC

f(n - 1, W):
    if(idx == 0):
        if(wt[0] <= W): 
            return val[0]
    return 0
    notTake = f(idx - 1, W)
    if(wt[idx] <= W):
         take = val[idx] + f(idx - 1, W - wt[idx])
    return max(take, notTake)
             
Memoization - O(nW) TC & SC

int recursion(int index, vector<int> &weight, vector<int> &value, int maxWeight, vector<vector<int>> &dp) {
    if(index == 0) {
        if(weight[0] <= maxWeight) return value[0];
        return 0;
    }
    if(dp[index][maxWeight] != -1)
        return dp[index][maxWeight];
    int take = 0;
    int notTake = 0 + recursion(index - 1, weight, value, maxWeight, dp);
    if(weight[index] <= maxWeight)
        take = value[index] + recursion(index - 1, weight, value, maxWeight - weight[index], dp);
    return dp[index][maxWeight] = max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)  {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return recursion(n - 1, weight, value, maxWeight, dp);
}

Tabulation - O(nW) TC & SC

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)  {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for(int wt = weight[0]; wt <= maxWeight; ++wt)
        dp[0][wt] = value[0];
    for(int idx = 1; idx < n; ++idx) {
        for(int wt = 0; wt <= maxWeight; ++wt) {
            int take = INT_MIN;
            int notTake = dp[idx - 1][wt];
            if(weight[idx] <= wt)
                take = value[idx] + dp[idx - 1][wt - weight[idx]];
            dp[idx][wt] = max(take, notTake);
        }
    }
    return dp[n - 1][maxWeight];
}

Space optimization over tabulation - O(nW) TC & O(W) SC

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)  {
    vector<int> dp(maxWeight + 1, 0);
    for(int wt = weight[0]; wt <= maxWeight; ++wt)
        dp[wt] = value[0];
    for(int idx = 1; idx < n; ++idx) {
        vector<int> current(maxWeight + 1, 0);
        for(int wt = 0; wt <= maxWeight; ++wt) {
            int take = INT_MIN;
            int notTake = dp[wt];
            if(weight[idx] <= wt)
                take = value[idx] + dp[wt - weight[idx]];
            current[wt] = max(take, notTake);
        }
        dp = current;
    }
    return dp[maxWeight];
}

Single row usage only

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)  {
    vector<int> dp(maxWeight + 1, 0);
    for(int wt = weight[0]; wt <= maxWeight; ++wt)
        dp[wt] = value[0];
    for(int idx = 1; idx < n; ++idx) {
        for(int wt = maxWeight; wt >= 0; --wt) {
            int take = INT_MIN;
            int notTake = dp[wt];
            if(weight[idx] <= wt)
                take = value[idx] + dp[wt - weight[idx]];
            dp[wt] = max(take, notTake);
        }
    }
    return dp[maxWeight];
}
