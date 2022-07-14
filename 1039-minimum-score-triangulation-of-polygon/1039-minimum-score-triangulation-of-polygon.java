class Solution {
    public int minScoreTriangulation(int[] values) {
        int n = values.length;
        int[][] dp = new int[n][n];
        for(int i = n - 1; i >= 1; --i) {
            for(int j = i + 1; j < n; ++j) {
                int minOperations = (int)1e9;
                for(int k = i; k < j; ++k) {
                    int steps = (values[i - 1] * values[k] * values[j]) + dp[i][k] + dp[k + 1][j];
                    minOperations = Math.min(minOperations, steps);
                }
                dp[i][j] = minOperations;
            }
        }
        return dp[1][n - 1];
    }
}