class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int n = size(nums), l = 0, r = n - 1, ans = 0, MOD = 1e9 + 7;
        vector<int> powers(n, 1);
        for(int i = 1; i < n; ++i)
            powers[i] = (powers[i - 1] * 2) % MOD;
        while(l <= r) {
            if(nums[l] + nums[r] > target) --r;
            else {
                ans = (ans + powers[r - l]) % MOD;
                ++l;
            }
        }
        return ans;
    }
};