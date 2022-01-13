class Solution {
    private:
    void solve(int idx, vector<int> &nums, vector<vector<int>> &ans) {
        if(idx == nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); ++i) {
            if(i != idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            solve(idx + 1, nums, ans);
        }
        for(int j = nums.size() - 1; j > idx; --j) {
            swap(nums[j], nums[idx]);
        }
    }
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(0, nums, ans);
        return ans;
    }
};