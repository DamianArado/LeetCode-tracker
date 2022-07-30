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

Approach 3: Using tabulation - O(n) TC & SC

class Solution {
public:
    // tc - O(n), sc - O(1)
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

Approach 4: Using space optimization over tabulation - O(n) TC & O(1) SC

**/

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 or n == 1) return 1;
        int prev2 = 1, prev = 1;
        for(int i = 2; i <= n; ++i) {
            int current = prev + prev2;
            prev2 = prev;
            prev = current;
        }
        return prev;
    }
};