class Solution {
private:
    int findSum(int row, int col, const int &n, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if (col < 0 or col > n - 1) 
            return 1e9;
        if (row == 0)
            return grid[row][col];
        if (dp[row][col] != -1)
            return dp[row][col];
        int current = grid[row][col], ans = INT_MAX;
        for (int colTemp = 0; colTemp < n; ++colTemp) {
            if (colTemp == col) continue;
            ans = min(ans, findSum(row - 1, colTemp, n, grid, dp));
        }
        return dp[row][col] = current + ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = size(grid), minSum = 1e9;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        // try starting with each element in the last row
        for (int i = 0; i < n; ++i)
            minSum = min(minSum, findSum(n - 1, i, n, grid, dp));
        return minSum;
    }
};