class Solution {
public:
    int longestContinuousSubstring(string s) {
        int len = 1, maxLen = 1;
        for(int i = 0; i < s.length() - 1; ++i) {
            if(s[i + 1] - s[i] == 1) {
                ++len;
                maxLen = max(maxLen, len);
            } else len = 1;
        }
        return maxLen;
    }
};