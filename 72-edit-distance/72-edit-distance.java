class Solution {
    public int minDistance(String word1, String word2) {
        int n1 = word1.length(), n2 = word2.length();
        int[] dp = new int[n2 + 1];
        for(int idx2 = 0; idx2 <= n2; ++idx2) dp[idx2] = idx2;
        for(int idx1 = 1; idx1 <= n1; ++idx1) {
            int[] current = new int[n2 + 1];
            current[0] = idx1;
            for(int idx2 = 1; idx2 <= n2; ++idx2) {
                if(word1.charAt(idx1 - 1) == word2.charAt(idx2 - 1))
                    current[idx2] = dp[idx2 - 1];
                else {
                    int insertion = current[idx2 - 1];
                    int deletion = dp[idx2];
                    int replacement = dp[idx2 - 1];
                    current[idx2] = 1 + Math.min(insertion, Math.min(deletion, replacement));
                }
            }
            dp = current;
        }
        return dp[n2];
    }
}