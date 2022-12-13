class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length, minPathSum = Integer.MAX_VALUE;
        int dp[] = new int[n];
        for(int j = 0; j < n; ++j)
            dp[j] = matrix[0][j];
        for(int i = 1; i < n; ++i) {
            int temp[] = new int[n];
            for(int j = 0; j < n; ++j) {
                int down = matrix[i][j] + dp[j];
                int downLeft = (int)1e7, downRight = (int)1e7;
                if(j > 0) downLeft = matrix[i][j] + dp[j - 1];
                if(j < n - 1) downRight = matrix[i][j] + dp[j + 1];
                temp[j] = Math.min(down, Math.min(downLeft, downRight));
            }
            dp = temp;
        }
        for(int j = 0; j < n; ++j)
            minPathSum = Math.min(minPathSum, dp[j]);
        return minPathSum;
    }
}