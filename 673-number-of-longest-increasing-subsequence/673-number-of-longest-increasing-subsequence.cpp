class Solution {
    // Using LIS calculation in one pass - O(n^2) time & O(n) space
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLIS = 0, numLIS = 0;
        if(n == 1) return 1;
        vector<int> dp(n, 1), count(n, 1);
        for(int idx = 1; idx < n; ++idx) {
            for(int prev = 0; prev < idx; ++prev) {
                // when we update it for the first time we just copy the count from prev
                if(nums[prev] < nums[idx] and 1 + dp[prev] > dp[idx]) {
                    dp[idx] = 1 + dp[prev];
                    count[idx] = count[prev];
                    // if we see the same no. of LIS again with prev, we add in the extra ones
                } else if(nums[prev] < nums[idx] and 1 + dp[prev] == dp[idx]) 
                    count[idx] += count[prev];
            }
            maxLIS = max(maxLIS, dp[idx]);
        }
        // add all the counts of those equal to maxLIS
        for(int idx = 0; idx < n; ++idx) 
            if(dp[idx] == maxLIS)
                numLIS += count[idx];
        return numLIS;
    }
};