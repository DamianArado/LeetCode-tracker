// 4 approaches and their explanation (must-read)
// https://leetcode.com/problems/daily-temperatures/discuss/1574808/C%2B%2BPython-3-Simple-Solutions-w-Explanation-Examples-and-Images-or-2-Monotonic-Stack-Approaches

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(size(T));
        for(int n = size(T), cur = n-2; cur >= 0; cur--) {
            int next = cur + 1;                         // start at next day & iterate till you find next warmer day (NWD)
            while(next < n && T[next] <= T[cur])        // jump till you reach NWD
                next += ans[next] ? ans[next] : n;      // ?: operator just to make sure that if we reach ans[next], we know NWD doesnt exist, so jump direct to end
            if(next < n) ans[cur] = next-cur;           // if next > n, NWD doesnt exist. Otherwise, assign distance to NWD
        }
        return ans;
    }
};