/***

This problem is just a way of asking us to find the number of ways to partition an array (into 2 subsets)
that has a difference of target: target = S1 - S2 where S1 and S2 are the subset sum of partition 1 and 
partition 2 respectively and S1 >= S2.

S1 - S2 = target
S1 + S2 = totalSum
S2 = (totalSum - target) / 2;

Thus, we now just need to find the total number of non-unique subsets that give us a sum of S2 out of nums
taking care of just 2 more edge cases: (totalSum - target > 0 and (totalSum - target) % 2 == 0)

Approach 1: Memoized solution

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

TC: O(n * target), SC: O(n * target + n)

Approach 2: Using Tabulation

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0, n = nums.size();
        for(int num : nums)
            totalSum += num;
        
        // Checking for edge cases
        if(totalSum - target < 0 | (totalSum - target) % 2 == 1) 
            return 0;
        
        int k = (totalSum - target) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        
        for(int index = 1; index <= n; ++index) {
            for(int target = 0; target <= k; ++target) {
                int notTake = dp[index - 1][target];
                int take = 0;
                if(nums[index - 1] <= target)
                    take = dp[index - 1][target - nums[index - 1]];
                dp[index][target] = take + notTake;
            }
        }
        
        return dp[n][k];
    }
};

TC & SC: O(nk)

Approach 3: Space-optimized bottom up tabulated DP

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0, n = nums.size();
        for(int num : nums)
            totalSum += num;
        
        // Checking for edge cases
        if(totalSum - target < 0 | (totalSum - target) % 2 == 1) 
            return 0;
        
        int k = (totalSum - target) / 2;
        vector<int> dp(k + 1, 0);
        vector<int> current(k + 1, 0);
        dp[0] = 1;
        
        for(int index = 1; index <= n; ++index) {
            for(int target = 0; target <= k; ++target) {
                int notTake = dp[target];
                int take = 0;
                if(nums[index - 1] <= target)
                    take = dp[target - nums[index - 1]];
                current[target] = take + notTake;
            }
            dp = current;
        }
        
        return dp[k];
    }
};

TC: O(nk), SC: O(k)


*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0, n = nums.size();
        for(int num : nums)
            totalSum += num;
        
        // Checking for edge cases
        if(totalSum - target < 0 | (totalSum - target) % 2 == 1) 
            return 0;
        
        int k = (totalSum - target) / 2;
        vector<int> dp(k + 1, 0);
        vector<int> current(k + 1, 0);
        dp[0] = 1;
        
        for(int index = 1; index <= n; ++index) {
            for(int target = 0; target <= k; ++target) {
                int notTake = dp[target];
                int take = 0;
                if(nums[index - 1] <= target)
                    take = dp[target - nums[index - 1]];
                current[target] = take + notTake;
            }
            dp = current;
        }
        
        return dp[k];
    }
};