class Solution {
    private int findLCS(String s, String reverse) {
        int n = s.length();
        int[] dp = new int[n + 1];
        for(int i = 1; i <= n; ++i) {
            int[] current = new int[n + 1];
            for(int j = 1; j <= n; ++j) {
                if(s.charAt(i - 1) == reverse.charAt(j - 1))
                    current[j] = 1 + dp[j - 1];
                else
                    current[j] = Math.max(dp[j], current[j - 1]);
            }
            dp = current;
        }
        return dp[n];
    }
    
    public int minInsertions(String s) {
        String reverse = new StringBuilder(s).reverse().toString();
        return s.length() - findLCS(s, reverse);
    }
}