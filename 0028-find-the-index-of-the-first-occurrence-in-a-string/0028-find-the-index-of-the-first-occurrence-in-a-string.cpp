/**
class Solution {
public:
    // brute force - O(n1.n2) TC & O(1) SC
    int strStr(string haystack, string needle) {
        int n1 = size(haystack), n2 = size(needle);
        for(int i = 0; i <= n1 - n2; ++i) {
            int j = 0;
            for(; j < n2; ++j) 
                if(haystack[i + j] != needle[j])
                    break;
            if(j == n2) return i;
        }
        return -1;
    }
};
*/
class Solution {
private:
    vector<int> constructLPS(string &needle) {
        int n = size(needle);
        vector<int> lps(n);
        int i = 0, j = 1;
        while(j < n) {
            if(needle[i] == needle[j]) {
                lps[j] = ++i, ++j;
            }
            else if(i == 0)
                lps[j] = 0, ++j;
            else 
                i = lps[i - 1];
        }
        return lps;
    }
public:
    // KMP - O(n1 + n2) TC & O(n2) SC
    int strStr(string haystack, string needle) {
        int n1 = size(haystack), n2 = size(needle);
        vector<int> lps = constructLPS(needle);
        for(int i = 0, j = 0; i < n1; ) {
            if(haystack[i] == needle[j])
                ++i, ++j;
            if(j == n2) 
                return i - j;
            if(haystack[i] != needle[j])
                j > 0 ? j = lps[j - 1] : ++i;
        }
        return -1;
    }
};