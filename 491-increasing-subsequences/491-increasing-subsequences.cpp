class Solution {
public:
    void helper(vector<int> &nums, vector<int> &subs, set<vector<int>> &result, int index) {
    
        for (int i = index; i < nums.size(); ++i) {
            if (subs.size() == 0 || nums[i] >= subs.back()) {
                subs.emplace_back(nums[i]);
                helper(nums, subs, result, i + 1);
                subs.pop_back();
            }
        }
        if (subs.size() >= 2) result.insert(subs);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> subs;
        helper(nums, subs, res, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
};