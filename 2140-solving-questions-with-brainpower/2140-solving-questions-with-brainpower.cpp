// Memoization
// class Solution {
// private:
//     long long f(int idx, int n, vector<vector<int>> &questions, vector<long long> &dp) {
//         if(idx >= n) return 0;
//         if(idx == n - 1) return questions[idx][0];
//         if(dp[idx]) return dp[idx];
//         long long solve = questions[idx][0] + f(idx + (questions[idx][1] + 1), n, questions, dp);
//         long long skip = f(idx + 1, n, questions, dp);
//         return dp[idx] = max(solve, skip);
//     }
// public:
//     long long mostPoints(vector<vector<int>>& questions) {
//         int n = size(questions);
//         vector<long long> dp(n);
//         return f(0, n, questions, dp);
//     }
// };

// Tabulation
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = size(questions);
        vector<long long> dp(n + 1);
        dp[n - 1] = questions[n - 1][0];
        for(int idx = n - 2; idx >= 0; --idx) {
            int point = questions[idx][0], bpower = questions[idx][1];
            long long solve = questions[idx][0] + dp[min(idx + bpower + 1, n)];
            long long skip = dp[idx + 1];
            dp[idx] = max(solve, skip);
        }
        return dp[0];
    }
};