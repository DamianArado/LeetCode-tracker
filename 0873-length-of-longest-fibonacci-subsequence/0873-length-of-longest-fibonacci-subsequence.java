class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length, maxLen = 0;
        int[][] dp = new int[n][n];
        for(int i = 2; i < n; ++i) {
            int l = 0, r = i - 1;
            while(l < r) {
                int sum = arr[l] + arr[r];
                if(sum > arr[i]) --r;
                else if(sum < arr[i]) ++l;
                else {
                    dp[r][i] = 1 + dp[l][r];
                    maxLen = Math.max(maxLen, dp[r][i]);
                    ++l;
                    --r;
                }
            }
        }
        return maxLen != 0 ? maxLen + 2 : maxLen;
    }
}