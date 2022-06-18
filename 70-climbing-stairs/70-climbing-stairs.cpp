/**
Solution 1 : Using Recursion - O(2^n) tc and O(n) sc
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
    
Solution 2 : Using memoization (recursion) - O(n) tc and O(n) sc
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

**/

class Solution {
public:
    // tc - O(n), sc - O(1)
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        int prev2 = 1, prev = 1;
        // no. of ways to climb 2 stairs -> climb n stairs
        //    prev2   prev   current
        //      0      1        2
        for(int i = 2; i <= n; ++i) {
            int current = prev + prev2;
            prev2 = prev;
            prev = current;
        }
        // prev is at n index now
        return prev;
    }
};