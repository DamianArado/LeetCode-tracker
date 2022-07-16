/**

Approach 1: Simple Recurrence - exponential TC & O(n) SC

class Solution {
private:
    bool isPalindrome(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            ++i; --j;
        }
        return true;
    }
    int f(int start, int n, string &s) {
        if(start == n) return 0;
        int minCuts = INT_MAX;
        for(int end = start; end < n; ++end) {
            if(isPalindrome(start, end, s)) {
                int cuts = 1 + f(end + 1, n, s);
                minCuts = min(minCuts, cuts);
            }
        }
        return minCuts;
    }
public:
    int minCut(string s) {
        int n = s.size();
        // due to a partition done at index n
        return f(0, n, s) - 1;
    }
};

Approach 2: Memoization - O(n^3) TC & O(2n) SC

class Solution {
private:
    bool isPalindrome(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            ++i; --j;
        }
        return true;
    }
    int f(int start, int n, string &s, vector<int> &dp) {
        if(start == n) return 0;
        if(dp[start] != -1) return dp[start];
        int minCuts = INT_MAX;
        for(int end = start; end < n; ++end) {
            if(isPalindrome(start, end, s)) {
                int cuts = 1 + f(end + 1, n, s, dp);
                minCuts = min(minCuts, cuts);
            }
        }
        return dp[start] = minCuts;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        // due to a partition done at index n
        return f(0, n, s, dp) - 1;
    }
};

Approach 3: Using tabulation - O(n^3) TC & O(n) SC

*/

class Solution {
private:
    bool isPalindrome(int i, int j, string &s) {
        while(i < j)
            if(s[i++] != s[j--]) return false;
        return true;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        for(int start = n - 1; start >= 0; --start) {
            int minCuts = INT_MAX;
            for(int end = start; end < n; ++end) {
                if(isPalindrome(start, end, s)) {
                    int cuts = 1 + dp[end + 1];
                    minCuts = min(minCuts, cuts);
                }
            }
            dp[start] = minCuts;
        }
        // due to a partition done at index n
        return dp[0] - 1;
    }
};