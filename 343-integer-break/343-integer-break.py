class Solution(object):
    def integerBreak(self, n):
        if n == 2 or n == 3:
            return n - 1
        ans = 1
        if n % 3 == 0:
            for i in range(n / 3):
                ans *= 3
        elif n % 3 == 1:
            for i in range(n / 3 - 1):
                ans *= 3;
            ans *= 4
        else:
            for i in range(n / 3):
                ans *= 3;
            ans *= 2
        return ans
        