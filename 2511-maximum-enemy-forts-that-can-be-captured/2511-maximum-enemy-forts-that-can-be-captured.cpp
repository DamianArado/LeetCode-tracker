class Solution {
public:
    // looking out for shit code? look no further
    int captureForts(vector<int>& forts) {
        int n = size(forts);
        if(n == 1) return 0;
        int ans = 0;
        // moving from left to right
        for(int i = 0; i < n; ++i) {
            if(forts[i] == 1) {
                int count = 0;
                for(int j = i + 1; j < n; ++j) {
                    if(j != n - 1 and forts[j] == 0) count++;
                    else if((j == n - 1 and forts[n - 1] == 0) or forts[j] == 1) { count = 0; break; }
                    else { break; }
                }
                ans = max(ans, count);
            }
        }
        // moving from right to left
        for(int i = n - 1; i >= 0; --i) {
            if(forts[i] == 1) {
                int count = 0;
                for(int j = i - 1; j >= 0; --j) {
                    if(j != 0 and forts[j] == 0) count++;
                    else if((j == 0 and forts[0] == 0) or forts[j] == 1) { count = 0; break; }
                    else { break; }
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};