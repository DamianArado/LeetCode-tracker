class Solution {
    public int longestContinuousSubstring(String s) {
        int len = 1, maxLen = 1;
        for(int i = 0; i < s.length() - 1; ++i) {
            if(s.charAt(i + 1) - s.charAt(i) == 1) {
                ++len;
                maxLen = Math.max(maxLen, len);
            } else len = 1;
        }
        return maxLen;
    }
}