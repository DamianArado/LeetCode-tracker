class Solution {
private:
    int f(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(col < 0 or col >= matrix.size()) return 1e7;
        if(row == 0) return matrix[0][col];
        if(dp[row][col] != -1) return dp[row][col];
        int up = matrix[row][col] + f(row - 1, col, matrix, dp);
        int upLeft = matrix[row][col] + f(row - 1, col - 1, matrix, dp);
        int upRight = matrix[row][col] + f(row - 1, col + 1, matrix, dp);
        return dp[row][col] = min(up, min(upLeft, upRight));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), minPath = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int minPathSum = INT_MAX; 
        for(int i = 0; i < n; ++i)
            minPathSum = min(minPathSum, f(n - 1, i, matrix, dp));
        return minPathSum;
    }
};