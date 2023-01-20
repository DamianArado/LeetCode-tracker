class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < size(nums); ++i) {
            // |x - y| = k => y = x - k and y = x + k
            // just check how many such y you have already seen before
            ans += (mp[nums[i] - k] + mp[nums[i] + k]);
            mp[nums[i]]++;
        }
        return ans;
    }
};