// class Solution {
// private:
//     int mincost(int idx, vector<int> &cost, vector<int> &dp) {
//         if(idx < 0) return 0;
//         if(idx == 0 or idx == 1) return cost[idx];
//         if(dp[idx] != -1) return dp[idx];
//         return dp[idx] = cost[idx] + min(mincost(idx - 1, cost, dp), mincost(idx - 2, cost, dp));
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = size(cost);
//         vector<int> dp(n, -1);
//         return min(mincost(n - 1, cost, dp), mincost(n - 2, cost, dp));
//     }
// };

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = size(cost);
//         vector<int> dp(n);
//         dp[0] = cost[0], dp[1] = cost[1];
//         for(int i = 2; i < n; ++i)
//             dp[i] = cost[i] + min(dp[i - 2], dp[i - 1]);
//         return min(dp[n - 2], dp[n - 1]);
//     }
// };

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = size(cost);
        int pprev = cost[0], prev = cost[1];
        for(int i = 2; i < n; ++i) {
            int current = cost[i] + min(pprev, prev);
            pprev = prev, prev = current;
        }
        return min(pprev, prev);
    }
};