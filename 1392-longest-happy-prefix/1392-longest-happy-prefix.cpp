class Solution {
public:
    string longestPrefix(string s) {
        // find out the longest prefix which is also a suffix
        int i = 0, j = 1, n = size(s);
        vector<int> lps(n);
        while(j < n) {
            // both matching
            if(s[i] == s[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            } else {
                // if the start is not even matching
                if(i == 0) {
                    lps[j] = 0;
                    j++;
                } else {
                    // move i back
                    i = lps[i - 1];
                }
            }
        }
        int prefixLen = lps.back();
        return s.substr(0, prefixLen);
    }
};