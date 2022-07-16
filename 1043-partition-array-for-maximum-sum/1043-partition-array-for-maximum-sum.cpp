/***

Approach 1: Using recursion - exponential time and O(n) space

class Solution {
private:
    int f(int start, int k, int n, vector<int> &arr) {
        if(start == n) return 0;
        int maxNum = -1, maxSum = 0, length = 0;
        for(int end = start; end < min(n, start + k); ++end) {
            maxNum = max(maxNum, arr[end]);
            length += 1;
            int sum = maxNum * length + f(end + 1, k, n, arr);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return f(0, k, n, arr);
    }
};

Approach 2: Using memoization over recursion - O(nk) TC & O(2n) SC

class Solution {
private:
    int f(int start, int k, int n, vector<int> &arr, vector<int> &dp) {
        if(start == n) return 0;
        if(dp[start] != -1) return dp[start];
        int maxNum = -1, maxSum = 0, length = 0;
        for(int end = start; end < min(n, start + k); ++end) {
            maxNum = max(maxNum, arr[end]);
            length += 1;
            int sum = maxNum * length + f(end + 1, k, n, arr, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[start] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, k, n, arr, dp);
    }
};

Approach 3: Using tabulation - O(nk) TC & O(n) SC

*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for(int start = n - 1; start >= 0; --start) {
            int maxNum = -1, maxSum = 0, length = 0;
            for(int end = start; end < min(n, start + k); ++end) {
                maxNum = max(maxNum, arr[end]);
                length += 1;
                int sum = maxNum * length + dp[end + 1];
                maxSum = max(maxSum, sum);
            }
            dp[start] = maxSum;
        }
        return dp[0];
    }
};