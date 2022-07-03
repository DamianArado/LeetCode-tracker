class Solution {
private:
    int findLCS(string &text1, string &text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<int> dp(n2 + 1, 0);
        for(int idx1 = 1; idx1 <= n1; ++idx1) {
            vector<int> current(n2 + 1, 0);
            for(int idx2 = 1; idx2 <= n2; ++idx2) {
                // match
                if(text1[idx1 - 1] == text2[idx2 - 1]) 
                    current[idx2] = 1 + dp[idx2 - 1];
                else 
                    current[idx2] = max(dp[idx2], current[idx2 - 1]);
            }
            dp = current;
        }
        return dp[n2];
    }
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == word2.size())
            return 2 * (word1.size() - findLCS(word1, word2));
        return word1.size() + word2.size() - 2 * findLCS(word1, word2);
    }
};