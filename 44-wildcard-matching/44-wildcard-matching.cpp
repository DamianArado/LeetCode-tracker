/**

Approach 1: Using recursion - exponential TC & O(n1 + n2) SC

class Solution {
private:
    bool f(int idx1, int idx2, string &s, string &p) {
        // base cases
        if(idx1 == -1 and idx2 == -1) return true;  // both s and p gets exhausted
        if(idx2 == -1 and idx1 >= 0) return false;  // if p gets exhausted
        if(idx1 == -1 and idx2 >= 0) { // if s gets exhausted
            for(int i = 0; i <= idx2; ++i)  // checking if its all *
                if(p[i] != '*') return false;
            return true;
        }
        
        // if there is a match or a '?'
        if(s[idx1] == p[idx2] or p[idx2] == '?')
            return f(idx1 - 1, idx2 - 1, s, p);
        // if we see a '*', lets figure how many time it will be considered
        if(p[idx2] == '*') {
            bool consider = f(idx1 - 1, idx2, s, p);
            bool notConsider = f(idx1, idx2 - 1, s, p);
            return consider or notConsider;
        }
        // no match
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        return f(n1 - 1, n2 - 1, s, p);
    }
};

Approach 2: Using memoization - O(n1.n2) TC & O(n1.n2 + (n1 + n2)) SC



*/

class Solution {
private:
    bool f(int idx1, int idx2, string &s, string &p, vector<vector<int>> &dp) {
        // base cases
        if(idx1 == -1 and idx2 == -1) return 1;  // both s and p gets exhausted
        if(idx2 == -1 and idx1 >= 0) return 0;  // if p gets exhausted
        if(idx1 == -1 and idx2 >= 0) { // if s gets exhausted
            for(int i = 0; i <= idx2; ++i)  // checking if its all *
                if(p[i] != '*') return 0;
            return 1;
        }
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        // if there is a match or a '?'
        if(s[idx1] == p[idx2] or p[idx2] == '?')
            return dp[idx1][idx2] = f(idx1 - 1, idx2 - 1, s, p, dp);
        // if we see a '*', lets figure how many time it will be considered
        if(p[idx2] == '*') {
            bool consider = f(idx1 - 1, idx2, s, p, dp);
            bool notConsider = f(idx1, idx2 - 1, s, p, dp);
            return dp[idx1][idx2] = consider or notConsider;
        }
        // no match
        return dp[idx1][idx2] = 0;
    }
public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return f(n1 - 1, n2 - 1, s, p, dp) == 1;
    }
};