class Solution {
public:
    int takeCharacters(string s, int k) {
        // intuition: find the max length of window such that the count of a, b and c in remaining
        // string is atleast k
        int n = size(s);
        int aCnt = count(begin(s), end(s), 'a');
        int bCnt = count(begin(s), end(s), 'b');
        int cCnt = n - (aCnt + bCnt);
        
        if(aCnt < k or bCnt < k or cCnt < k) return -1;
        
        int j = 0, ans = n + 1, window = 0;
        for(int i = 0; i < n; ++i) {
            aCnt -= (s[i] == 'a');
            bCnt -= (s[i] == 'b');
            cCnt -= (s[i] == 'c');
            ++window;
            // criteria not satisfied
            while(aCnt < k or bCnt < k or cCnt < k) {
                aCnt += (s[j] == 'a');
                bCnt += (s[j] == 'b');
                cCnt += (s[j] == 'c');
                --window, ++j;
            }
            ans = min(ans, n - window);
        }
        
        return ans;
    }
};