class Solution {
    private int solve(int idx1, String word1, int idx2, String word2, int[][] dp) {
        // base cases
        if(idx1 == -1) return idx2 + 1;
        if(idx2 == -1) return idx1 + 1;
        
        // return the pre-calculated result
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        // possible outcomes
        // match
        if(word1.charAt(idx1) == word2.charAt(idx2))
            return dp[idx1][idx2] = solve(idx1 - 1, word1, idx2 - 1, word2, dp);
        // not a match
        int addition = solve(idx1, word1, idx2 - 1, word2, dp);
        int replacement = solve(idx1 - 1, word1, idx2 - 1, word2, dp);
        int deletion = solve(idx1 - 1, word1, idx2, word2, dp);
        return dp[idx1][idx2] = 1 + Math.min(addition, Math.min(replacement, deletion));
    }
    public int minDistance(String word1, String word2) {
        int n1 = word1.length(), n2 = word2.length();
        int[][] dp = new int[n1][n2];
        for(var arr : dp)
            Arrays.fill(arr, -1);
        return solve(n1 - 1, word1, n2 - 1, word2, dp);
    }
}