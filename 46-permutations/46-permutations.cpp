class Solution {
    private: 
    void solve(int idx, vector<int> &nums, vector<vector<int>> &ans) {
        if(idx == nums.size() - 1) {
            ans.emplace_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); ++i) {
            // swap in place
            swap(nums[i], nums[idx]);
            solve(idx + 1, nums, ans);
            // backtrack
            swap(nums[i], nums[idx]);
        }
    }
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};