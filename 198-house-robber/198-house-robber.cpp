/**

Basic approach

1. Represent the problem in terms of indices
2. Do all stuffs while staying on that index
3. Minimize or Maximize the answer according to the constraints (Return the best possible)

Approach 1 - memoization : O(n) tc & sc (recursive stack space too)

int f(int index, vector<int> &nums, vector<int> &dp) {
    if(index < 0) return 0;
    if(index == 0) return nums[index];
    if(dp[index] != -1) return dp[index];
    
    int pick = nums[index] + f(index - 2, nums, dp);
    int dontPick = f(index - 1, nums, dp);
    return dp[index] = max(pick, dontPick);
}

int rob(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(n - 1, nums, dp);
}


Approach 2 - tabulation : O(n) tc & sc

int rob(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for(int i = 1; i < n; ++i) {
        int pick = nums[i];
        if(i >= 2) pick += dp[i - 2];
        int dontPick = 0 + dp[i - 1];
        dp[i] = max(pick, dontPick);
    }
    return dp[n - 1];
}

**/

class Solution {
public:
    int rob(vector<int>& nums) {
        // this is a problem that can be solved efficiently using 1d DP
        int n = nums.size();
        // I'll be using space optimization over the tabulation approach
        // for negative index we didn't return anything earlier too
        int prev2 = 0, prev = nums[0];
        for(int i = 1; i < n; ++i) {
            // take money from the current index house
            int pick = nums[i] + prev2;
            // dont take from this house and take from the next one
            int dontPick = 0 + prev;
            // store the max that you can get till now
            int currentMax = max(pick, dontPick);
            // move to rob the next houses
            prev2 = prev;
            prev = currentMax;
        }
        // this loops end when i == n, return the answer as the last index
        return prev;
    }
};