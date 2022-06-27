class Solution {
private:
    bool subsetSumEqualsK(int index, int k, vector<int> &nums) {
        vector<bool> dp(k + 1, false), current(k + 1, false);
        dp[0] = current[0] = true;
        if(nums[0] <= k) 
            dp[nums[0]] = true;
        for(int index = 1; index < nums.size(); ++index) {
            for(int target = 1; target <= k; ++target) {
                bool notTake = dp[target];
                bool take = false;
                if(nums[index] <= target)
                    take = dp[target - nums[index]];
                current[target] = take | notTake;
            }
            dp = current;
        }
        return dp[k];
    }
public:
    // If it has odd sum return false as we can't divide it into 2 equal halves
    // If it has even sum, use subset sum equal to k logic for k = totalSum / 2
    // TC: O(n*k), SC: O(n)
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totalSum = 0;
        for(int num : nums) 
            totalSum += num;
        if(totalSum % 2 == 1) return false;
        int k = totalSum / 2;
        return subsetSumEqualsK(n - 1, k, nums);
    }
};