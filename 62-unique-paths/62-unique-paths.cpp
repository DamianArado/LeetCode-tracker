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

Solution 2 - Using Tabulation based approach

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

TC and SC - O(mn)

Approach 3 - Using space optimization

// TC - O(mn) SC - O(n)
    int uniquePaths(int m, int n) {
        // to store the previous states
        vector<int> dp(n, 0);
        // iterate row-by-row
        for(int row = 0; row < m; ++row) {
            // to store the current states
            vector<int> temp(n, 0);
            for(int col = 0; col < n; ++col) {
                if(row == 0 and col == 0) {
                    temp[col] = 1;
                    continue;
                }
                // store the value taken from the left and top of grid [row,col]
                int left = 0, up = 0;
                if(col > 0) left = temp[col - 1];
                if(row > 0) up = dp[col];
                temp[col] = left + up;
            }
            // float to the next row (helpful in calculation)
            dp = temp;
        }
        // return the last entry of the last column we are standing at
        return dp[n - 1];
    }

*/

class Solution {
public:
    // TC - O(min(m,n)) using combinatorics
    int uniquePaths(int m, int n) {
        // total unique directions
        int N = m + n - 2;
        // how much we have to move down or right (whichever minimum) in order to reach the destination
        int R = min(m - 1, n - 1);
        double result = 1;
        // N c R
        for(int i = 1; i <= R; ++i)
            result = result * (N - R + i) / i;
        return (int)result;
    }
};