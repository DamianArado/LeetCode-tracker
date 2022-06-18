/**
Solution 1 : Using Recursion - O(2^n) tc and O(n) sc
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }

**/

class Solution {
private:
    int climbStairs(int n, vector<int> &dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climbStairs(n, dp);
    }
};