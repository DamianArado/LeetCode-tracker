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
    
TC: O(9^m), SC: O(m)  [TLE]

Approach 2: Applying Memoization using a 3D DP 

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
    
TC: O(9 * m*n*n), SC: O(m*n*n + n)

Approach 3: Using Tabulation (m - 1, j1, j2) -> (0, 0, n - 1)

int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, 0)));
        // base cases
        for(int j1 = 0; j1 < n; ++j1) {
            for(int j2 = 0; j2 < n; ++j2) {
                if(j1 == j2) dp[m - 1][j1][j2] = grid[m - 1][j1];
                else dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }
        // moving bottom-up
        for(int i = m - 2; i >= 0; --i) {
            for(int j1 = 0; j1 < n; ++j1) {
                for(int j2 = 0; j2 < n; ++j2) {
                    int cherry = 0, maxCherries = 0;
                    // dj is change in j for alice and bob
                    // it will 9 possible movements of Alice and Bob combined
                    for(int djAlice = -1; djAlice <= 1; ++djAlice) {
                        for(int djBob = -1; djBob <= 1; ++djBob) {
                            // if they take the same cell, consider only one of them
                            if(j1 == j2) cherry = grid[i][j1];
                            // else consider both of them
                            else cherry = grid[i][j1] + grid[i][j2];
                            // only if the value is within bounds, add it
                            if(j1 + djAlice >= 0 and j1 + djAlice < n and j2 + djBob >= 0 and j2 + djBob < n)
                                cherry += dp[i + 1][j1 + djAlice][j2 + djBob];
                            // else add a very negative no. which will not be considered
                            else cherry += -1e8;
                            // take the max of the cherries picked
                            maxCherries = max(maxCherries, cherry);
                        }
                    }
                    // add max cherries for this cell
                    dp[i][j1][j2] = maxCherries;
                }
            }
        }
        // return the cherries generated at this cell as this will be the max that were picked up
        return dp[0][0][n - 1];
    }

Approach 4: Improving SC over tabulation

TC: O(9*m*n*n), SC: O(n*n)

*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // we just need a dp of size = n x n to store the previous states of Bob and Alice
        // and this will help us in calculating their next states
        vector<vector<int>> dp(n, vector<int> (n, 0));
        // position of columns of alice and bob: dp[alice][bob]
        // base cases
        for(int j1 = 0; j1 < n; ++j1) {
            for(int j2 = 0; j2 < n; ++j2) {
                if(j1 == j2)
                    dp[j1][j2] = grid[m - 1][j1];
                else 
                    dp[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }
        
        // moving in a bottom-up fashion
        for(int i = m - 2; i >= 0; --i) {
            // to store the current states calculated using the previous states
            vector<vector<int>> current(n, vector<int> (n, 0));
            for(int j1 = 0; j1 < n; ++j1) {
                for(int j2 = 0; j2 < n; ++j2) {
                    int maxCherries = -1e8;
                    // since both can move in a total of 9 combinations
                    // dj is delta j: -1, 0, +1
                    for(int djAlice = -1; djAlice <= 1; ++djAlice) {
                        for(int djBob = -1; djBob <= 1; ++djBob) {
                            // cherries should be initialized and added during each of the 9 movements
                            int cherries = 0; 
                            if(j1 == j2) 
                                cherries = grid[i][j1];
                            else 
                                cherries = grid[i][j1] + grid[i][j2];
                            // just making sure we don't go out of bounds
                            if(j1 + djAlice >= 0 and j1 + djAlice < n and j2 + djBob >= 0 and j2 + djBob < n)
                                cherries += dp[j1 + djAlice][j2 + djBob];
                            else 
                                cherries += -1e8;
                            maxCherries = max(maxCherries, cherries);
                        }
                    }
                    current[j1][j2] = maxCherries;
                }
            }
            // move row-by-row
            dp = current;
        }
        return dp[0][n - 1];
    }
};