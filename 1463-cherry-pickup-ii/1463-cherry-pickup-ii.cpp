/**

Approach 1: Using Recursion  

private:
    int f(vector<vector<int>> &grid, int i, int j1, int j2, int m, int n) {
        // out of bound base case
        if(j1 < 0 or j1 > n - 1 or j2 < 0 or j2 > n - 1)
            return -1e8;
        // destination base case
        if(i == m - 1) {
            if(j1 == j2)
                // return any one of them
                return grid[i][j1];
            else 
                // return the sum of them
                return grid[i][j1] + grid[i][j2];
        }
        // explore all paths: there can be 9 possible combinations everytime
        int maxPathSum = 0;
        // dj is delta j: types of changes in j when we move to the next row
        // we see 9 combinations: for every movement of alice, bob can move to 3 locations
        for(int djAlice = -1; djAlice <= 1; ++djAlice) {
            for(int djBob = -1; djBob <= 1; ++djBob) {
                if(j1 == j2)
                    maxPathSum = max(maxPathSum, 
                                     grid[i][j1] + f(grid, i + 1, j1 + djAlice, j2 + djBob, m, n));
                else 
                    maxPathSum = max(maxPathSum, 
                                     grid[i][j1] + grid[i][j2] + f(grid, i + 1, j1 + djAlice, j2 + djBob, m, n));
            }
        }
        return maxPathSum;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return f(grid, 0, 0, n - 1, m, n);
    }
    
TC: O(9^m), SC: O(m)           [TLE]




*/

class Solution {
private:
    int f(vector<vector<int>> &grid, int i, int j1, int j2, int m, int n, vector<vector<vector<int>>> &dp) {
        // out of bound base case
        if(j1 < 0 or j1 > n - 1 or j2 < 0 or j2 > n - 1)
            return -1e8;
        // destination base case
        if(i == m - 1) {
            if(j1 == j2)
                // return any one of them
                return grid[i][j1];
            else 
                // return the sum of them
                return grid[i][j1] + grid[i][j2];
        }
        // if its already solved (visited), return it as answer
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        // explore all paths: there can be 9 possible combinations everytime
        int maxPathSum = 0;
        // dj is delta j: types of changes in j when we move to the next row
        // we see 9 combinations: for every movement of alice, bob can move to 3 locations
        for(int djAlice = -1; djAlice <= 1; ++djAlice) {
            for(int djBob = -1; djBob <= 1; ++djBob) {
                if(j1 == j2)
                    maxPathSum = max(maxPathSum, 
                                     grid[i][j1] + f(grid, i + 1, j1 + djAlice, j2 + djBob, m, n, dp));
                else 
                    maxPathSum = max(maxPathSum, 
                                     grid[i][j1] + grid[i][j2] + f(grid, i + 1, j1 + djAlice, j2 + djBob, m, n, dp));
            }
        }
        return dp[i][j1][j2] = maxPathSum;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));
        return f(grid, 0, 0, n - 1, m, n, dp);
    }
};