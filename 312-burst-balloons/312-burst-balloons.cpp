/**

Approach 1: Recurrence

class Solution {
private:
    int recursion(int i, int j, vector<int> &nums) {
        // base case
        if(i > j) return 0;
        // try out all the balloons for the one to be bursted
        int maxCoins = 0;
        for(int idx = i; idx <= j; ++idx) {
            //  1 [ idx ] 1
            //    i     j
            int coins = (nums[i - 1] * nums[idx] * nums[j + 1]) + recursion(i, idx - 1, nums) 
                + recursion(idx + 1, j, nums);
            maxCoins = max(maxCoins, coins);
        }
        return maxCoins;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // in this approach we find out the last balloon to be bursted, then 2nd last, and so on..
        // this will help us in partitioning as the subproblems will be independent of each other
        return recursion(1, n, nums);
    }
};

Approach 2: Using memoization - O(n^3) TC & O(n^2 + n) SC

class Solution {
private:
    int recursion(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        // base case
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        // try out all the balloons for the one to be bursted
        int maxCoins = 0;
        for(int idx = i; idx <= j; ++idx) {
            //  1 [ idx ] 1
            //    i     j
            int coins = (nums[i - 1] * nums[idx] * nums[j + 1]) + recursion(i, idx - 1, nums, dp) 
                + recursion(idx + 1, j, nums, dp);
            maxCoins = max(maxCoins, coins);
        }
        return dp[i][j] = maxCoins;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // in this approach we find out the last balloon to be bursted, then 2nd last, and so on..
        // this will help us in partitioning as the subproblems will be independent of each other
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return recursion(1, n, nums, dp);
    }
};

Approach 3: Tabulation - O(n^3) TC & O(n^2) SC


*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));
        
        for(int i = n; i >= 1; --i) {
            for(int j = 1; j <= n; ++j) {
                if(i > j) continue;
                int maxCoins = 0;
                for(int idx = i; idx <= j; ++idx) {
                    int coins = (nums[i - 1] * nums[idx] * nums[j + 1]) + dp[i][idx - 1] + dp[idx + 1][j];
                    maxCoins = max(maxCoins, coins);
                }
                dp[i][j] = maxCoins;
            }
        }
        return dp[1][n];
    }
};