/***

Memoized solution - 

private:
    int countSubsetsWithSumK(vector<int> &nums, int index, int target, vector<vector<int>>& dp) {
        if(index == 0) {
            if(target == 0 and nums[0] == 0) return 2;
            if(target == 0 or target == nums[0]) return 1;
            return 0;
        }
        if(dp[index][target] != -1) return dp[index][target];
        int take = 0;
        int notTake = countSubsetsWithSumK(nums, index - 1, target, dp);
        if(target >= nums[index])
            take = countSubsetsWithSumK(nums, index - 1, target - nums[index], dp);
        return dp[index][target] = take + notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0, n = nums.size();
        if(n == 1 and target == -nums[0]) return 1;
        if(n == 1 and target != nums[0]) return 0;
        for(int num : nums)
            totalSum += num;
        int k = (totalSum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return countSubsetsWithSumK(nums, n - 1, k, dp);
    }
    
This will not work


*/

class Solution {
private:
    int countSubsetsWithSumK(vector<int> &nums, int index, int target, vector<vector<int>>& dp) {
        if(index == 0) {
            if(target == 0 and nums[0] == 0) return 2;
            if(target == 0 or target == nums[0]) return 1;
            return 0;
        }
        if(dp[index][target] != -1) return dp[index][target];
        int take = 0;
        int notTake = countSubsetsWithSumK(nums, index - 1, target, dp);
        if(target >= nums[index])
            take = countSubsetsWithSumK(nums, index - 1, target - nums[index], dp);
        return dp[index][target] = take + notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0, n = nums.size();
        //if(n == 1 and target == -nums[0]) return 1;
        //if(n == 1 and target != nums[0]) return 0;
        for(int num : nums)
            totalSum += num;
        // Checking for edge cases
        if(totalSum - target < 0) return 0;
        if((totalSum - target) % 2 == 1) return 0;
        int k = (totalSum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return countSubsetsWithSumK(nums, n - 1, k, dp);
    }
};