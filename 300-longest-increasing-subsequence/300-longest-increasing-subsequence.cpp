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

class Solution {
private:
    int f(int index, int previous, int n, vector<int>& nums, vector<vector<int>> &dp) {
        if(index == n) return 0;
        // since we explicitly cannot access array index -1
        // previous is stored at [0...n - 1] instead of [-1...n - 2]
        if(dp[index][previous + 1] != -1) return dp[index][previous + 1];
        int take = 0, notTake = 0;
        if(previous == -1 or nums[previous] < nums[index])
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

Approach 3: Using tabulation - O(n^2) TC & SC

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for(int index = n - 1; index >= 0; --index) {
            for(int previous = index - 1; previous >= -1; --previous) {
                int take = 0, notTake = 0;
                if(previous == -1 or nums[previous] < nums[index])
                    take = 1 + dp[index + 1][(index) + 1];
                notTake = dp[index + 1][previous + 1];
                dp[index][previous + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};

Approach 3: Using space optimization over tabulation - O(n^2) TC & O(n) SC

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> current(n + 1, 0);
        for(int index = n - 1; index >= 0; --index) {
            vector<int> next(n + 1, 0);
            for(int previous = index - 1; previous >= -1; --previous) {
                int take = 0, notTake = 0;
                if(previous == -1 or nums[previous] < nums[index])
                    take = 1 + current[(index) + 1];
                notTake = current[previous + 1];
                next[previous + 1] = max(take, notTake);
            }
            current = next;
        }
        return current[0];
    }
};

Approach 4: Another approach based on tabulation - O(n^2) TC & O(n) SC



*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLIS = 1;
        vector<int> dp(n, 1);
        for(int index = 0; index < n; ++index) {
            for(int previous = 0; previous < index; ++previous) {
                if(nums[previous] < nums[index])
                    dp[index] = max(dp[index], 1 + dp[previous]);
            }
            maxLIS = max(maxLIS, dp[index]);
        }
        return maxLIS;
    }
};