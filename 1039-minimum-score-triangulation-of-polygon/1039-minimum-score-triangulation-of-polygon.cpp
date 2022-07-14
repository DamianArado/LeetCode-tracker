/**

We can easily solve this problem using the concept of Matrix Chain Multiplication

Approach 1: Recursion based solution - exponential TC & O(N) SC

class Solution {
private:
    int f(int i, int j, vector<int> &values) {
        // base case
        if(i == j) return 0;  // no more operations required
        int minOperations = 1e9;
        // lets figure out the partitions
        for(int k = i; k < j; ++k) {
            int steps = values[i - 1] * values[k] * values[j] + f(i, k, values) + f(k + 1, j, values);
            if(steps < minOperations)
                minOperations = steps;
        }
        return minOperations;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return f(1, n - 1, values);
    }
};

Approach 2: Using memoization - O(N^3) TC & O(N^2) SC




*/


class Solution {
private:
    int f(int i, int j, vector<int> &values, vector<vector<int>> &dp) {
        // base case
        if(i == j) return 0;  // no more operations required
        if(dp[i][j] != -1) return dp[i][j];
        int minOperations = 1e9;
        // lets figure out the partitions
        for(int k = i; k < j; ++k) {
            int steps = values[i - 1] * values[k] * values[j] + f(i, k, values, dp) + f(k + 1, j, values, dp);
            if(steps < minOperations)
                minOperations = steps;
        }
        return dp[i][j] = minOperations;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(1, n - 1, values, dp);
    }
};