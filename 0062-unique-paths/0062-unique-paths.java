class Solution {
    public int uniquePaths(int m, int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        for(int row = 0; row < m; ++row) {
            int[] current = new int[n];
            current[0] = 1;
            for(int col = 0; col < n; ++col) {
                if(row == 0 && col == 0) continue;
                int right = 0, down = 0;
                if(col - 1 >= 0) right = current[col - 1];
                if(row - 1 >= 0) down = dp[col];
                current[col] = right + down;
            }
            dp = current;
        }
        return dp[n - 1];
    }
}