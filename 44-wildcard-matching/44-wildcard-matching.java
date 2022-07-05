class Solution {
    public boolean isMatch(String s, String p) {
        int n1 = s.length(), n2 = p.length();
        boolean[] dp = new boolean[n2 + 1];
        dp[0] = true;
        for(int idx2 = 1; idx2 <= n2; ++idx2) {
            boolean allAsterisks = true;
            for(int i = 1; i <= idx2; ++i) {
                if(p.charAt(i - 1) != '*') {
                    allAsterisks = false;
                    break;
                }
            }
            dp[idx2] = allAsterisks;
        }
        for(int idx1 = 1; idx1 <= n1; ++idx1) {
            boolean[] current = new boolean[n2 + 1];
            for(int idx2 = 1; idx2 <= n2; ++idx2) {
                if(s.charAt(idx1 - 1) == p.charAt(idx2 - 1) | p.charAt(idx2 - 1) == '?')
                    current[idx2] = dp[idx2 - 1];
                else if(p.charAt(idx2 - 1) == '*') {
                    boolean consider = dp[idx2];
                    boolean notConsider = current[idx2 - 1];
                    current[idx2] = consider | notConsider;
                } else current[idx2] = false;
            }
            dp = current;
        }
        return dp[n2];
    }
}