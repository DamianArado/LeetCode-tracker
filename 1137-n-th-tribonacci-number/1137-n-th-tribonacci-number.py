class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0: return 0;
        if n <= 2: return 1;
        ppprev, pprev, prev = 0, 1, 1;
        for i in range(3, n + 1):
            current = ppprev + pprev + prev;
            ppprev, pprev, prev = pprev, prev, current;
        return prev;