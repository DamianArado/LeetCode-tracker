class Solution {
private:
    bool solve(int i, int j, string &str, string &pat, vector<vector<int>> &dp) {
        // both get matched 
        if(i == size(str) and j == size(pat)) return true;
        // pattern gets exhausted
        if(j == size(pat)) return false;
        // precomputed value
        if(dp[i][j] != -1) return dp[i][j];
        // string gets exhausted
        if(i == size(str)) {
            if(pat[j + 1] == '*')
                // start matching from the next index after *
                return dp[i][j] = solve(i, j + 2, str, pat, dp);
            return dp[i][j] = false;
        }
        // checking if the preceding element of * is . or a matching element or not
        if(j + 1 < size(pat) and pat[j + 1] == '*') {
            if(pat[j] == '.' or str[i] == pat[j])
                // either match string and keep matching due to * or don't match at all
                return dp[i][j] = solve(i + 1, j, str, pat, dp) or solve(i, j + 2, str, pat, dp);
            else 
                // not a match with the preceding element so you move ahead of *
                return dp[i][j] = solve(i, j + 2, str, pat, dp);
        } 
        // if there is a match
        else if(pat[j] == '.' or str[i] == pat[j])
            return dp[i][j] = solve(i + 1, j + 1, str, pat, dp);
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n1 = size(s), n2 = size(p);
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};