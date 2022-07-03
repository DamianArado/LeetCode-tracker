class Solution {
    private int findLCS(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int[] dp = new int[n + 1];
        for(int i = 1; i <= m; ++i) {
            int[] current = new int[n + 1];
            for(int j = 1; j <= n; ++j) {
                if(s1.charAt(i - 1) == s2.charAt(j - 1))
                    current[j] = 1 + dp[j - 1];
                else
                    current[j] = Math.max(dp[j], current[j - 1]);
            }
            dp = current;
        }
        return dp[n];
    }
    public int minDistance(String word1, String word2) {
        return word1.length() + word2.length() - 2 * findLCS(word1, word2);
    }
}