class Solution {
    // Longest common substring
    public int findLength(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length, ans = 0;
        int[] dp = new int[n + 1];
        for(int i = 1; i <= m; ++i) {
            int[] current = new int[n + 1];
            for(int j = 1; j <= n; ++j) {
                if(nums1[i - 1] == nums2[j - 1]) {
                    if(dp[j - 1] != 0) {
                        current[j] = dp[j - 1] + 1;
                        ans = Math.max(ans, current[j]);
                    } else {
                        current[j] = 1;
                        ans = Math.max(ans, current[j]);
                    }
                } else {
                    current[j] = 0;
                }
            }
            dp = current;
        }
        return ans;
    }
}