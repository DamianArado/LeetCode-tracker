// sollveeddd   a a   hardd questionn by myselffff      yayyyyyyyyyyyyyyyyy!
// Memoization
// class Solution {
// private:
//     // sollveeddd   a a   hardd questionn by myselffff      yayyyyyyyyyyyyyyyyy!
//     int f(int idx, int time, vector<int> &satisfaction, vector<vector<int>> &dp) {
//         if(idx == size(satisfaction)) return 0;
//         if(dp[idx][time] != -1) return dp[idx][time];
//         int take = satisfaction[idx] * time + f(idx + 1, time + 1, satisfaction, dp);
//         int notTake = f(idx + 1, time, satisfaction, dp);
//         return dp[idx][time] = max(take, notTake);
//     }
// public:
//     int maxSatisfaction(vector<int>& satisfaction) {
//         int n = size(satisfaction);
//         sort(begin(satisfaction), end(satisfaction));
//         vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
//         return f(0, 1, satisfaction, dp);
//     }
// };

// Tabulation
// class Solution {
// public:
//     int maxSatisfaction(vector<int>& satisfaction) {
//         int n = size(satisfaction);
//         sort(begin(satisfaction), end(satisfaction));
//         vector<vector<int>> dp(n + 1, vector<int> (n + 2));
//         for(int i = n - 1; i >= 0; --i) {
//             for(int time = n; time >= 1; --time) {
//                 int take = satisfaction[i] * time + dp[i + 1][time + 1]; 
//                 int notTake = dp[i + 1][time];
//                 dp[i][time] = max(take, notTake);
//             }
//         }
//         return dp[0][1];
//     }
// };

// space optimized DP
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = size(satisfaction);
        sort(begin(satisfaction), end(satisfaction));
        vector<int> dp(n + 2);
        for(int i = n - 1; i >= 0; --i) {
            vector<int> current(n + 2);
            for(int time = n; time >= 1; --time) {
                int take = satisfaction[i] * time + dp[time + 1]; 
                int notTake = dp[time];
                current[time] = max(take, notTake);
            }
            dp = current;
        }
        return dp[1];
    }
};