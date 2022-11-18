/***

Recurrence - O(2^n) time and O(n) space

class Solution {
private:
    int solve(int i, int mod, vector<int> &nums) {
        if(i < 0) {
            if(mod == 0) return 0;
            return -1e9;
        }
        int pick = nums[i] + solve(i - 1, (mod + nums[i]) % 3, nums);
        int notPick = solve(i - 1, mod, nums);
        return max(pick, notPick);
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = size(nums);
        return solve(n - 1, 0, nums);
    }
};

Memoized - O(3*n) time & O(3*n + n) space

class Solution {
private:
    int solve(int i, int mod, vector<int> &nums, vector<vector<int>> &dp) {
        if(i < 0) {
            if(mod == 0) return 0;
            return -1e9;
        }
        if(dp[i][mod] != -1) return dp[i][mod];
        int pick = nums[i] + solve(i - 1, (mod + nums[i]) % 3, nums, dp);
        int notPick = solve(i - 1, mod, nums, dp);
        return dp[i][mod] = max(pick, notPick);
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = size(nums);
        vector<vector<int>> dp(n, vector<int> (3, -1));
        return solve(n - 1, 0, nums, dp);
    }
};

Tabulation - O(3*n) time and O(1) space

*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN};
        for(int &num : nums) {
            vector<int> temp(3);
            for(int remainder = 0; remainder < 3; ++remainder)
                temp[(remainder + num) % 3] = max(dp[(remainder + num) % 3], dp[remainder] + num);
            dp = temp;
        }
        return dp[0];
    }
};