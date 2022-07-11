class Solution {
    // TC: O(n^2) SC: O(n)
public:
    // Using the concept of printing LIS using one pass algorithm and 2 auxilary arrays
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        // to not check for increasing as well as divisibility for each no. 
        sort(begin(nums), end(nums));
        // dp: used for calculating the LIS, hash: at any index, tells the position of the previous guy to it
        vector<int> dp(n, 1), hash(n);
        iota(begin(hash), end(hash), 0);
        // the count of elements in our LIS, index of the last element in LIS
        int maxLIS = 1, lastIdx = 0;
        for(int i = 1; i < n; ++i) {
            for(int prev = 0; prev < i; ++prev) {
                // check for divisibilty and take into DP
                if(nums[i] % nums[prev] == 0 and dp[i] < 1 + dp[prev]) {
                    // if the count until now exceeds
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            // update the count of elements in our LIS just in case
            if(dp[i] > maxLIS) {
                maxLIS = dp[i];
                lastIdx = i;
            }
        }
        // Longest Divisible Subsequence
        vector<int> lds;
        // obviously
        lds.push_back(nums[lastIdx]);
        // till we reach the last element in LIS
        while(hash[lastIdx] != lastIdx) {
            lastIdx = hash[lastIdx];
            lds.push_back(nums[lastIdx]);
        }
        // reverse to get the required LDS
        reverse(begin(lds), end(lds));
        return lds;
    }
};