class Solution {
private:
    int mincost(int idx, const vector<int> &cost, vector<int> &dp) {
        if (idx < 0) 
            return INT_MAX;
        if (idx == 0 or idx == 1) 
            return cost[idx];
        if (dp[idx] != -1) 
            return dp[idx];
        return dp[idx] = cost[idx] + 
            min(mincost(idx - 1, cost, dp), mincost(idx - 2, cost, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = size(cost);
        vector<int> dp(n, -1);
        return min(mincost(n - 1, cost, dp), mincost(n - 2, cost, dp));
    }
};