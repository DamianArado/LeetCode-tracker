class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // dp[i] : min taps to water till index i
        vector<int> dp(n + 1, n + 2);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            int left = max(0, i - ranges[i]), right = min(n, i + ranges[i]);
            for (int j = left + 1; j <= right; ++j)
                dp[j] = min(dp[j], dp[left] + 1);
        }
        return dp[n] >= n + 2 ? -1 : dp[n];
    }
};