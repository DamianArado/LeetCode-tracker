class Solution {
    public int cherryPickup(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dp = new int[n][n];
        for(int j1 = 0; j1 < n; ++j1) {
            for(int j2 = 0; j2 < n; ++j2) {
                if(j1 == j2)
                    dp[j1][j2] = grid[m - 1][j1];
                else 
                    dp[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }
        for(int i = m - 2; i >= 0; --i) {
            int[][] current = new int[n][n];
            for(int j1 = 0; j1 < n; ++j1) {
                for(int j2 = 0; j2 < n; ++j2) {
                    int maxCherries = (int)-1e8;
                    for(int djAlice = -1; djAlice <= 1; ++djAlice) {
                        for(int djBob = -1; djBob <= 1; ++djBob) {
                            // cherries should be initialized and added during each of these 9 movements
                            int cherries = 0;
                            if(j1 == j2)
                                cherries = grid[i][j1];
                            else 
                                cherries = grid[i][j1] + grid[i][j2];
                            if(j1 + djAlice >= 0 && j1 + djAlice < n && j2 + djBob >= 0 && j2 + djBob < n)
                                cherries += dp[j1 + djAlice][j2 + djBob];
                            else 
                                cherries += (int)-1e8;
                            maxCherries = Math.max(maxCherries, cherries);
                        }
                    }
                    current[j1][j2] = maxCherries;
                }
            }
            dp = current;
        }
        return dp[0][n - 1];
    }
}