class Solution {
    public int longestIdealString(String s, int k) {
        int[] dp = new int[26];
        int maxLen = 0;
        for(int i = 0; i < s.length(); ++i) {
            int charIdx = s.charAt(i) - 'a', ans = 1;
            for(int c = 0; c < 26; ++c)
                if(Math.abs(c - charIdx) <= k)
                    ans = Math.max(ans, dp[c] + 1);
            dp[charIdx] = ans;
            maxLen = Math.max(maxLen, dp[charIdx]);
        }
        return maxLen;
    }
}