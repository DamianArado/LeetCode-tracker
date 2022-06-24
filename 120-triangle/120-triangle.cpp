/**

Approach 1: Recurrence
f(i,j):
    if i == n - 1:
        return a[i][j]
    down = a[i][j] + f(i + 1, j)
    diagonalRight = a[i][j] + f(i + 1, j + 1)
    return min(down, diagonal)
    
TC: O(2^(n^2)) as 2^(1+2+3+....+n)     [TLE]
SC: O(n)

Approach 2: Memoization
private:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i == triangle.size() - 1) return triangle[i][j];
        int down = triangle[i][j] + f(i + 1, j, triangle, dp);
        int diagonalRight = triangle[i][j] + f(i + 1, j + 1, triangle, dp);
        return dp[i][j] = min(down, diagonalRight);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, triangle, dp);
    }
    
TC: O(1+2+3+....+n) = O(n^2)     [TLE]
SC: O(n^2 + n)

Approach 3: Tabulation



*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // base cases
        for(int j = 0; j < n; ++j)
            dp[n - 1][j] = triangle[n - 1][j];
        // move opposite to recursion - bottom up
        // (n - 1) -> (0, 0)
        for(int i = n - 2; i >= 0; --i) {
            for(int j = i; j >= 0; --j) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonalRight = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonalRight);
            }
        }
        // answer is waiting here
        return dp[0][0];
    }
};