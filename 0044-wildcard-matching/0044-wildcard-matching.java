class Solution {
    public boolean isMatch(String s, String p) {
        int n1 = s.length(), n2 = p.length();
        boolean dp[][] = new boolean[n1 + 1][n2 + 1];
        dp[0][0] = true;
        for(int idx2 = 1; idx2 <= n2; ++idx2) { // when s gets exhausted
            // there will only be a matching if we are sure that there will be only * left in p
            boolean allAsterisk = true;
            // don't start from 0 as cases like: s = "abc" & p = "*" returns false
            for(int i = 1; i <= idx2; ++i) {
                if(p.charAt(i - 1) != '*') {
                    allAsterisk = false;
                    break;
                }
            }
            dp[0][idx2] = allAsterisk;
        }
        for(int idx1 = 1; idx1 <= n1; ++idx1) {
            for(int idx2 = 1; idx2 <= n2; ++idx2) {
                if((s.charAt(idx1 - 1) == p.charAt(idx2 - 1)) || p.charAt(idx2 - 1) == '?')
                    dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1];
                else if(p.charAt(idx2 - 1) == '*') 
                    dp[idx1][idx2] = dp[idx1 - 1][idx2] || dp[idx1][idx2 - 1];
                else dp[idx1][idx2] = false;
            }
        }
        return dp[n1][n2];
    }
}