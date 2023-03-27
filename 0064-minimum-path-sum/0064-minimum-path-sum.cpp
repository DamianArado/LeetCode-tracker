/**

Approach 1: Using memoization - O(mn) tc and O(mn + (m+n)) sc

    int f(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(m == 0 and n == 0) return grid[0][0];
        if(m < 0 or n < 0) return 1e7;
        if(dp[m][n] != -1) return dp[m][n];
        int left = grid[m][n] + f(m, n - 1, grid, dp);
        int up = grid[m][n] + f(m - 1, n, grid, dp);
        return dp[m][n] = min(left, up);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(m - 1, n - 1, grid, dp);
    }

Approach 2: Using tabulation - O(mn) tc and sc

int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 and j == 0) dp[i][j] = grid[0][0];
                else {
                    int left = 0, up = 0;
                    
                    if(j > 0) left += grid[i][j] + dp[i][j - 1];
                    else left += 1e7;
                    
                    if(i > 0) up += grid[i][j] + dp[i - 1][j];
                    else up += 1e7;
                    
                    dp[i][j] = min(left, up);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    
Approach 3: Using space optimization

**/

class Solution {
public:
    // tc - O(mn) sc - O(n)
    int minPathSum(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]);
        // will act as the previous state for temp
        vector<int> dp(n);
        for(int i = 0; i < m; ++i) {
            // current state while doing down row by row
            vector<int> temp(n);
            for(int j = 0; j < n; ++j) {
                if(i == 0 and j == 0) temp[j] = grid[0][0];
                else {
                    int left = 0, up = 0;
                    
                    if(j > 0) left += grid[i][j] + temp[j - 1];
                    else left += 1e7;
                    
                    if(i > 0) up += grid[i][j] + dp[j];
                    else up += 1e7;
                    
                    temp[j] = min(left, up);
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};