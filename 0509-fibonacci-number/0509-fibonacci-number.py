class Solution:
    def fib(self, n: int) -> int:
        if n == 0: return 0
        if n == 1 or n == 2: return 1
        frst, scnd = 0, 1
        for i in range (2, n + 1):
            ans = frst + scnd
            frst = scnd
            scnd = ans
        return scnd