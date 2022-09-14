class Solution {
public:
    int longestIdealString(string s, int k) {
        // here, dp[i] signifies the length of the longest ideal subsequence ending at the index i 
        vector<int> dp(26);
        for(int i = 0; i < s.length(); ++i) {
            int charIdx = s[i] - 'a', ans = 1;
            for(int c = 0; c < 26; ++c) 
                if(abs(c - charIdx) <= k)
                    ans = max(ans, dp[c] + 1);
            dp[charIdx] = ans;
        }
        return *max_element(dp.begin(), dp.end());
    }
};