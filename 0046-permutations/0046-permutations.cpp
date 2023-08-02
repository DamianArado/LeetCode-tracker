class Solution {
private:
    void backtrack(vector<int> &nums, vector<vector<int>> &ans, int &sz, int i) {
        if (i == sz) 
            ans.emplace_back(nums);
        else
            for (int j = i; j <= sz; ++j) {
                swap(nums[i], nums[j]);
                backtrack(nums, ans, sz, i + 1);
                swap(nums[i], nums[j]);
            }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int sz = size(nums) - 1;
        backtrack(nums, ans, sz, 0);
        return ans;
    }
};