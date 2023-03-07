class Solution {
public:
    string reverseWords(string s) {
        reverse(begin(s), end(s));
        int i = 0, j = 0, n = size(s), lastIdx = 0;
        while(j < n) {
            while(j < n and s[j] == ' ') ++j;
            int startIdx = i;
            while(j < n and s[j] != ' ') {
                s[i++] = s[j++];
                lastIdx = i;
            }
            s[i++] = ' ';
            reverse(begin(s) + startIdx, begin(s) + lastIdx);
        }
        s.resize(lastIdx);
        return s;
    }
};