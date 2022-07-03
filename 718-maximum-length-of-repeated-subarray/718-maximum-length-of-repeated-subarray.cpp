class Solution {
public:
    // Using the logic of Longest common substring
    // TC & SC: O(mn)
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), ans = 0;
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(nums1[i - 1] == nums2[j - 1]) {
                    // match: check if we already have any match before this index on both nums1 and nums2
                    if(dp[i - 1][j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        ans = max(ans, dp[i][j]);
                    } else {
                        // no previous matches
                        dp[i][j] = 1;
                        ans = max(ans, dp[i][j]);
                    }
                } else {
                    // not a match
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};