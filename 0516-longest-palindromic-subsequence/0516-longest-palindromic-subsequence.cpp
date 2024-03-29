// TC: O(n^2), SC: O(n)
class Solution {
private:
    int findLCS(const string &s1, const string &s2) {
        int n = s1.size();
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; ++i) {
            vector<int> current(n + 1);
            for(int j = 1; j <= n; ++j) {
                // match
                if(s1[i - 1] == s2[j - 1])
                    current[j] = 1 + dp[j - 1];
                // not a match
                else 
                    current[j] = max(dp[j], current[j - 1]);
            }
            dp = current;
        }
        return dp[n];
    }
public:
    int longestPalindromeSubseq(string &s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return findLCS(s1, s2);
    }
};