/***

Approach 1: Recurrence (n - 1, j) -> (0, j)

f(row, col):
    if(col < 0 or col >= n): return INT_MAX
    if(row == 0): return a[0][col]
    up = f(row - 1, col)
    upLeft = f(row - 1, col - 1)
    upRight = f(row - 1, col + 1)
    return min(up, upLeft, upRight)
    
TC: O(3^n), SC: O(n)

Approach 2: Memoization as we see overlapping subproblems

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
    
TC: O(n^2), SC: O(n^2 + n)

Approach 3: Tabulation based approach (0, j) -> (n - 1, j)

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), minPathSum = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // base case: setting values for the 1st row
        for(int j = 0; j < n; ++j)
            dp[0][j] = matrix[0][j];
        // lets start from the 2nd row
        for(int i = 1; i < n; ++i) {
            // and from the 1st column
            for(int j = 0; j < n; ++j) {
                // calculating the values down, downLeft and downRight using the values in their above row
                int down = matrix[i][j] + dp[i - 1][j];
                int downLeft = 1e7, downRight = 1e7;
                if(j > 0) 
                    downRight = matrix[i][j] + dp[i - 1][j - 1];
                if(j < n - 1)
                    downLeft = matrix[i][j] + dp[i - 1][j + 1];
                dp[i][j] = min(down, min(downLeft, downRight));
            }
        }
        // what's the min among each of the entries collected in the last row
        for(int j = 0; j < n; ++j) 
            minPathSum = min(minPathSum, dp[n - 1][j]);
        return minPathSum;
    }

TC and SC: O(n^2)

Approach 4: Space optimization over tabulation - O(n^2) time and O(n) space

*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), minPathSum = INT_MAX;
        // to store the states of the previous row
        vector<int> dp(n, 0);
        // base case: add the states of the first row bro
        for(int j = 0; j < n; ++j)
            dp[j] = matrix[0][j];
        // now start row-wise from the second row
        for(int i = 1; i < n; ++i) {
            // to store the states of the current row
            vector<int> temp(n, 0);
            // make sure not to go beyond the boundaries
            for(int j = 0; j < n; ++j) {
                int down = matrix[i][j] + dp[j];
                int downLeft = 1e7, downRight = 1e7;
                if(j < n - 1) downLeft = matrix[i][j] + dp[j + 1];
                if(j > 0) downRight = matrix[i][j] + dp[j - 1];
                temp[j] = min(down, min(downLeft, downRight));
            }
            dp = temp;
        }
        // find out the minimum path taken among all the entries in the last column
        for(int i = 0; i < n; ++i)
            minPathSum = min(minPathSum, dp[i]);
        return minPathSum;
    }
};