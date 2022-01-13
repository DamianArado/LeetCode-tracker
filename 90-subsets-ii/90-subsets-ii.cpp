class Solution {
    private:
    void solve(int idx, vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums) {
        ans.emplace_back(ds);
        for(int i = idx; i < nums.size(); ++i) {
            if(i != idx && nums[i] == nums[i - 1]) continue;
            ds.emplace_back(nums[i]);
            solve(i + 1, ds, ans, nums);
            ds.pop_back();
        }
    }
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(0, ds, ans, nums);
        return ans;
    }
};