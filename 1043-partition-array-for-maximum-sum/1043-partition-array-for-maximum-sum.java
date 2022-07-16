class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n + 1];
        for(int start = n - 1; start >= 0; --start) {
            int maxNum = -1, maxSum = 0, length = 0;
            for(int end = start; end < Math.min(n, start + k); ++end) {
                maxNum = Math.max(maxNum, arr[end]);
                length += 1;
                int sum = maxNum * length + dp[end + 1];
                maxSum = Math.max(maxSum, sum);
            }
            dp[start] = maxSum;
        }
        return dp[0];
    }
}