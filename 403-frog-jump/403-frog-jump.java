class Solution {
    public boolean canCross(int[] stones) {
        int n = stones.length;
        boolean[][] dp = new boolean[n][n];
        dp[0][1] = true;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                int jump = stones[i] - stones[j];
                if(jump >= n || !dp[j][jump]) 
                    continue;
                if(jump - 1 >= 0) 
                    dp[i][jump - 1] = true;
                if(jump + 1 < n) 
                    dp[i][jump + 1] = true;
                
                dp[i][jump] = true;
                if(i == n - 1) return true;
            }
        }
        return false;
    }
}