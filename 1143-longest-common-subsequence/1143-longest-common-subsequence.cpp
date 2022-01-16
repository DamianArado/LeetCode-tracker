class Solution {
public:
    short longestCommonSubsequence(string text1, string text2) {
        // We are considering that text1 > text2 for storing size of min(text1, text2) + 1 in columns 
        // and size of rows as 2 only since we look upto only 1 row above
        if(text2.size() > text1.size()) return longestCommonSubsequence(text2, text1);
        // a table of [2][(min(text1, text2))]
        vector<vector<short>> m (2, vector<short> (text2.size() + 1));
        for(auto i = 1; i <= text1.size(); ++i) {
            for(auto j = 1; j <= text2.size(); ++j) {
                if(text1[i - 1] == text2[j - 1]) m[i % 2][j] = m[(i - 1) % 2][j - 1] + 1;
                else m[i % 2][j] = max(m[(i - 1) % 2][j], m[i % 2][j - 1]);
            }
        }
        return m[text1.size() % 2][text2.size()];
    }
};