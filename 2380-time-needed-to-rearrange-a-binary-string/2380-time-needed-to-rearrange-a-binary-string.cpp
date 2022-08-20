class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        bool flag = false;
        int n = s.length(), swaps = 0, ans = 0;
        while(!flag) {
            swaps = 0;
            for(int j = 0; j < n - 1; ++j) {
                if(s[j] == '0' and s[j + 1] == '1') {
                    s[j] = '1', s[j + 1] = '0';
                    ++j, ++swaps;
                }
            }
            if(swaps > 0) ans += 1;
            else if(swaps == 0) flag = true;
        }
        return ans;
    }
};