/***

Recurrence:

f(idx1, idx2): in s[0....idx1], how many distinct subsequences of t[0...idx2] can you find?
    if idx2 == -1: return 1
    if idx1 == -1: return 0
    take = f(idx1 - 1, idx2 - 1)
    notTake = f(idx1 - 1, idx2)
    if s[idx1] == t[idx2]:
        return take + notTake
    return notTake

Approach 1: Using memoization over recurrence - O(n1.n2) TC & O(n1.n2 + n1 + n2) SC 

class Solution {
private:
    int find(int idx1, int idx2, string &s, string &t, vector<vector<int>> &dp) {
        if(idx2 == -1) return 1;
        if(idx1 == -1) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int take = find(idx1 - 1, idx2 - 1, s, t, dp);
        int notTake = find(idx1 - 1, idx2, s, t, dp);
        if(s[idx1] == t[idx2])
            // need to take a mod with 1e9 + 7 to avoid integer overflow
            return dp[idx1][idx2] = (take + notTake) % prime;
        return dp[idx1][idx2] = notTake;
    }
public:
    int prime = 1e9 + 7;
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return find(n1 - 1, n2 - 1, s, t, dp);
    }
};

Approach 2: Using tabulation (bottom - up) - O(n1.n2) TC & SC

class Solution {
public:
    int numDistinct(string s, string t) {
        int prime = 1e9 + 7;
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
        for(int idx1 = 0; idx1 <= n1; ++idx1)
            dp[idx1][0] = 1;
        for(int idx1 = 1; idx1 <= n1; ++idx1) {
            for(int idx2 = 1; idx2 <= n2; ++idx2) {
                int take = dp[idx1 - 1][idx2 - 1];
                int notTake = dp[idx1 - 1][idx2];
                if(s[idx1 - 1] == t[idx2 - 1])
                    dp[idx1][idx2] = (take + notTake)  % prime;
                else
                    dp[idx1][idx2] = notTake;
            }
        }
        return dp[n1][n2];
    }
};

Approach 3: Space optimization over tabulation - O(n1.n2) TC & O(n2) SC

*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int prime = 1e9 + 7;
        int n1 = s.size(), n2 = t.size();
        vector<int> dp (n2 + 1, 0);
        dp[0] = 1;
        for(int idx1 = 1; idx1 <= n1; ++idx1) {
            vector<int> current (n2 + 1, 0);
            // V IMP
            current[0] = 1;
            for(int idx2 = 1; idx2 <= n2; ++idx2) {
                int take = dp[idx2 - 1];
                int notTake = dp[idx2];
                if(s[idx1 - 1] == t[idx2 - 1])
                    current[idx2] = (take + notTake)  % prime;
                else
                    current[idx2] = notTake;
            }
            dp = current;
        }
        return dp[n2];
    }
};
