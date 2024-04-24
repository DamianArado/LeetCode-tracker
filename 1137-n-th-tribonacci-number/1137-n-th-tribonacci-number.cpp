class Solution {
public:
    int tribonacci(int n) {
        if (n == 0 ) return 0;
        if (n == 1 or n == 2) return 1;
        int ppprev = 0, pprev = 1, prev = 1;
        for (int i = 3; i <= n; ++i) {
            int current = prev + pprev + ppprev;
            ppprev = pprev;
            pprev = prev;
            prev = current;
        }
        return prev;
    }
};