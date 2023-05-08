class Solution {
private:
    void constructLPS(string &needle, vector<int> &lps, int n2) {
        int i = 0, j = 1;
        /***
        a a b f g a b g a a
        0 1 0 0 0 1 0 0 1 2
        Longest prefix which is also a suffix
        ***/
        while(j < n2) {
            // if we see a prefix which is also a suffix we add the index there
            if(needle[i] == needle[j]) lps[j] = ++i, ++j;
            // if its at the start
            else if(i == 0) ++j;
            // otherwise we move back to lps[i - 1] as we don't see a match further
            else i = lps[i - 1];
        }
    }
public:
    int strStr(string haystack, string needle) {
        int n1 = size(haystack), n2 = size(needle);
        // construct the LPS table
        vector<int> lps(n2);
        constructLPS(needle, lps, n2);
        // start matching 
        for(int i = 0, j = 0; i < n1; ) {
            // we move both fwd
            if(haystack[i] == needle[j]) ++j, ++i;
            // we move j backward and not i
            else j > 0 ? j = lps[j - 1] : ++i;
            if(j == n2) return i - j;
        }
        return -1;
    }
};