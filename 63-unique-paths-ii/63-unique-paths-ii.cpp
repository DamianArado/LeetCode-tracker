/**

Solution 1: Using memoization - O(mn) tc and sc

private:
    int f(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp) {
        if(m < 0 or n < 0 or obstacleGrid[m][n] == 1) return 0;
        if(m == 0 and n == 0) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        int left = 0, up = 0;
        if(m > 0) left = f(m - 1, n, obstacleGrid, dp);
        if(n > 0) up = f(m, n - 1, obstacleGrid, dp);
        return dp[m][n] = left + up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, obstacleGrid, dp);
    }
    
Solution 2: Using tabulation - O(mn) tc and sc (w/o Recursion Stack Space of O(m + n))

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // check for obstacles first otherwise you'll get wrong answer
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 and j == 0) dp[i][j] = 1;
                else {
                    int left = 0, up = 0;
                    if(j > 0) left = dp[i][j - 1];
                    if(i > 0) up = dp[i - 1][j];
                    dp[i][j] = left + up;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    

Solution 3: Using space optimization over tabulation - 
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        for(int i = 0; i < m; ++i) {
            vector<int> temp(n, 0);
            for(int j = 0; j < n; ++j) {
                if(obstacleGrid[i][j] == 1) temp[j] = 0;
                else if(i == 0 and j == 0) temp[j] = 1;
                else {
                    int left = 0, up = 0;
                    if(j > 0) left = temp[j - 1];
                    if(i > 0) up = dp[j];
                    temp[j] = left + up;
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};