class Solution {
private:
    int findLCS(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= m; ++i) {
            vector<int> current(n + 1, 0);
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