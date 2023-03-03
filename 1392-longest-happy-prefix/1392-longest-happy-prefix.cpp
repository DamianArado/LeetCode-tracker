class Solution {
public:
    string longestPrefix(string s) {
        // find out the longest prefix which is also a suffix
        int i = 0, j = 1, n = size(s);
        vector<int> lps(n);
        while(j < n) {
            // Case 1: both matching
            if(s[i] == s[j]) {
                lps[j] = i + 1;
                ++i;
                ++j;
             } 
            // Case 2: if the start is not even matching
             else if(i == 0) {
                lps[j] = 0;
                ++j;
             }
             // Case 3: the mid portion is not matching
             else {
                    // move i back
                    i = lps[i - 1];
            }
        }
        int prefixLen = lps.back();
        return s.substr(0, prefixLen);
    }
};