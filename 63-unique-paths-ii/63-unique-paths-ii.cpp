class Solution {
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
};