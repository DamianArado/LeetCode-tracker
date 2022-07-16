class Solution {
    public static boolean isPalindrome(int start, int end, String s) {
        while(start < end) {
            if(s.charAt(start) != s.charAt(end)) return false;
            ++start;
            --end;
        }
        return true;
    }
    public int minCut(String s) {
        int n = s.length();
        int dp[] = new int[n + 1];
        
        for(int start = n - 1; start >= 0; --start) {
            int minCuts = Integer.MAX_VALUE;
            for(int end = start; end < n; ++end) {
                if(isPalindrome(start, end, s)) {
                    int cuts = 1 + dp[end + 1];
                    minCuts = Math.min(minCuts, cuts);
                }
            }
            dp[start] = minCuts;
        }
        return dp[0] - 1;
    }
}