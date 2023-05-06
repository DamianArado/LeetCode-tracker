class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int n = size(nums), l = 0, r = n - 1, ans = 0, MOD = 1e9 + 7;
        vector<int> powers(n, 1);
        // power of 2 
        for(int i = 1; i < n; ++i)
            powers[i] = (powers[i - 1] * 2) % MOD;
        while(l <= r) {
            // 2 sum logic
            if(nums[l] + nums[r] > target) --r;
            else {
                // adding subsequences using this line
                // adding 2 ^ (r - l) subsequences to answer
                // basically under any given condition if we want to take subsequences then 
                // b/w l and r, add 2 ^ (r - l) subsequences
                // 2 ^ x subsequences because for x elements, there are 2 ^ x ways in which 
                // we can either take or not take them in our subsequence
                ans = (ans + powers[r - l]) % MOD;
                // move forward to count more subsequences
                ++l;
            }
        }
        return ans;
    }
};