class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if "0" in [num1, num2]:
            return "0"
        n1, n2 = len(num1), len(num2)
        res = [0] * (n1 + n2)
        num1, num2 = num1[::-1], num2[::-1]

        for i in range(n1):
            for j in range(n2):
                digit = int(num1[i]) * int(num2[j])
                res[i + j] += digit
                res[i + j + 1] += (res[i + j] // 10) # remainder
                res[i + j] = res[i + j] % 10 # make sure to keep it one digit

        res, begin = res[::-1], 0
        while begin < (n1 + n2) and res[begin] == 0:
            begin += 1
        res = map(str, res[begin:])
        return "".join(res)