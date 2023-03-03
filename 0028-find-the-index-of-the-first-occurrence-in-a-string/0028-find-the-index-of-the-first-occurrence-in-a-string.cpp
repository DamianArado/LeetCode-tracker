class Solution {
public:
    // brute force
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