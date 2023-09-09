class Solution {
private:
    int f(int idx, const int &n, const vector<int> &nums, const int &target, vector<vector<int>> &dp) {
        if (idx == n or target < 0) 
            return 0;
        if (target == 0)
            return 1;
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int take = f(0, n, nums, target - nums[idx], dp);
        int skip = f(idx + 1, n, nums, target, dp);
        return dp[idx][target] = take + skip;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = size(nums);
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        return f(0, n, nums, target, dp);
    }
};