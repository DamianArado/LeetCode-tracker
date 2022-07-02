class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n1 = text1.length(), n2 = text2.length();
        int[] dp = new int[n2 + 1];
        for(int idx1 = 1; idx1 <= n1; ++idx1) {
            int[] current = new int[n2 + 1];
            for(int idx2 = 1; idx2 <= n2; ++idx2) {
                if(text1.charAt(idx1 - 1) == text2.charAt(idx2 - 1)) 
                    current[idx2] = 1 + dp[idx2 - 1];
                else 
                    current[idx2] = Math.max(dp[idx2], current[idx2 - 1]);
            }
            dp = current;
        }
        return dp[n2];
    }
}