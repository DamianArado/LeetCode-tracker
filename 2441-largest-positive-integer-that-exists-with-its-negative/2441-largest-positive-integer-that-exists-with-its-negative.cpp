class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < size(nums); ++i) {
            if (mp.count(nums[i]) == 1)
                ans = max(ans, (nums[i] > 0 ? nums[i] : -nums[i]));
            mp[-nums[i]]++;
        }
        return ans;
    }
};