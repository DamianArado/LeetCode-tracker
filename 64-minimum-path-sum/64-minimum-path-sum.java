class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] dp = new int[n];
        for(int i = 0; i < m; ++i) {
            int[] temp = new int[n];
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) temp[j] = grid[0][0];
                else {
                    int left = 0, up = 0;
                    
                    if(j > 0) left += grid[i][j] + temp[j - 1];
                    else left += 1e7;
                    
                    if(i > 0) up += grid[i][j] + dp[j];
                    else up += 1e7;
                    
                    temp[j] = Math.min(left, up);
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
}