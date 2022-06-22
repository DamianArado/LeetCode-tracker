/*
Solution 1 - Memoizing the recurrence

f(i, j):
    if i == 0 and j == 0:
        return 1
    if i < 0 or j < 0:
        return 0
    left = f(i, j - 1)
    up = f(i - 1, j)
    return left + up

TC - O(2^mn) 
SC - O(path length) ~ O(m + n)

class Solution {
private:
    int f(int m, int n, vector<vector<int>> &dp) {
        // base case
        if(m == 0 and n == 0) 
            return 1;
        if(m < 0 or n < 0)
            return 0;
        if(dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = f(m, n - 1, dp) + f(m - 1, n, dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp);
    }
};

TC - O(mn) as we can have mn calls at max 
SC - O(mn) + (m + n)

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 and j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};