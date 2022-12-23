class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1 or n == 2) return 1;
        int frst = 0, scnd = 1;
        for(int i = 2; i <= n; ++i) {
            int ans = frst + scnd;
            frst = scnd;
            scnd = ans;
        }
        return scnd;
    }
};