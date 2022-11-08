class Solution {
public:
    string makeGood(string s) {
        int idx = 0;
        for(int i = 0; i < size(s); ++i) {
            if(idx > 0 and abs(s[idx - 1] - s[i]) == 32) --idx;
            else s[idx++] = s[i];
        }
        return s.substr(0, idx);
    }
};