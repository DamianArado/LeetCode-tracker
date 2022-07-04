class Solution {
    public int numDistinct(String s, String t) {
        int n1 = s.length(), n2 = t.length();
        int[] dp = new int[n2 + 1];
        dp[0] = 1;
        for(int idx1 = 1; idx1 <= n1; ++idx1) {
            int[] current = new int[n2 + 1];
            current[0] = 1;
            for(int idx2 = 1; idx2 <= n2; ++idx2) {
                int take = dp[idx2 - 1];
                int notTake = dp[idx2];
                if(s.charAt(idx1 - 1) == t.charAt(idx2 - 1))
                    current[idx2] = take + notTake;
                else
                    current[idx2] = notTake;
            }
            dp = current;
        }
        return dp[n2];
    }
}