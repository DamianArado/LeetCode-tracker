class Solution {
public:
    // take max of : prefix OR till ith index | (2^k * nums[i]) | suffixOR after index i
    long long maximumOr(vector<int>& nums, int k) {
        int n = size(nums);
        vector<long long> prefixOR(n + 1), suffixOR(n + 1);
        for(int i = 0; i < n; ++i) {
            prefixOR[i + 1] = prefixOR[i] | nums[i];
            suffixOR[n - i - 1] = suffixOR[n - i] | nums[n - i - 1];
        }
        long long ans = 0, mult = pow(2, k);
        for(int i = 0; i < n; ++i)
            ans = max(ans, prefixOR[i] | (nums[i] * mult) | suffixOR[i + 1]);
        return ans;
    }
};