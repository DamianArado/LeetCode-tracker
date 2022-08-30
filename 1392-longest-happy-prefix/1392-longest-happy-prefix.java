class Solution {
    public String longestPrefix(String s) {
        int n = s.length(), i = 0, j = 1;
        int[] lps = new int[n];
        while(j < n) {
            if(s.charAt(i) == s.charAt(j)) {
                lps[j] = i + 1;
                ++i;
                ++j;
            } else if(i == 0) {
                lps[j] = 0;
                ++j;
            } else {
                i = lps[i - 1];
            }
        }
        int prefixLen = lps[n - 1];
        return s.substring(0, prefixLen);
    }
}