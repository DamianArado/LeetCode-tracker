/***

Approach 1: Recurrence - O(2^n) TC & O(n) SC

class Solution {
private:
    int f(int index, int previous, int n, vector<int>& nums) {
        if(index == n) return 0;
        int take = 0, notTake = 0;
        if(previous == -1 or nums[previous] < nums[index])
            take = 1 + f(index + 1, index, n, nums);
        notTake = f(index + 1, previous, n, nums);
        return max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return f(0, -1, n, nums);
    }
};

Approach 2: Using memoization over recurrence - O(n^2) TC & SC of O(n^2 + n)


*/

class Solution {
private:
    int f(int index, int previous, int n, vector<int>& nums, vector<vector<int>> &dp) {
        if(index == n) return 0;
        if(dp[index][previous + 1] != -1) return dp[index][previous + 1];
        int take = 0, notTake = 0;
        if(previous + 1 == 0 or nums[previous] < nums[index])
            take = 1 + f(index + 1, index, n, nums, dp);
        notTake = f(index + 1, previous, n, nums, dp);
        return dp[index][previous + 1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(0, -1, n, nums, dp);
    }
};