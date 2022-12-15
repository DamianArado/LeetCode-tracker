class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long dp[] = new long[n];
        dp[n - 1] = questions[n - 1][0];
        for(int idx = n - 2; idx >= 0; --idx) {
            int point = questions[idx][0], bpower = questions[idx][1];
            long solve = questions[idx][0], skip = dp[idx + 1];
            if(idx + bpower + 1 < n) solve += dp[idx + bpower + 1];
            dp[idx] = Math.max(solve, skip);
        }
        return dp[0];
    }
}