class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) ans.emplace_back(nums[nums[i]]);
        return ans;
    }
};