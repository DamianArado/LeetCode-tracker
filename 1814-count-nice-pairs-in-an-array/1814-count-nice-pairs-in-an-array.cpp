class Solution {
private:
    int findReverse(int num) {
        int ans = 0;
        for(; num > 0; num /= 10)
            ans = ans * 10 + num % 10;
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        // nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
        int ans = 0, mod = 1e9 + 7;
        unordered_map<int, int> mp;
        for(int i = 0; i < size(nums); ++i)
            ans = (ans + mp[nums[i] - findReverse(nums[i])]++) % mod;
        return ans;
    }
};