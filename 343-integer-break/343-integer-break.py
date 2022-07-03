class Solution(object):
    def integerBreak(self, n):
        if n == 2 or n == 3:
            return n - 1
        ans = 1
        remainder = n % 3
        quotient = n / 3
        if remainder == 0:
            ans = pow(3, quotient)
        elif remainder == 1:
            ans = 4 * pow(3, quotient - 1)
        else:
            ans = 2 * pow(3, quotient)
        return ans
        