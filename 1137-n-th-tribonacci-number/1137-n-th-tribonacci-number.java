class Solution {
    public int tribonacci(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;
        int ppprev = 0, pprev = 1, prev = 1;
        for(int i = 3; i <= n; ++i) {
            int current = ppprev + pprev + prev;
            ppprev = pprev;
            pprev = prev;
            prev = current;
        }
        return prev;
    }
}