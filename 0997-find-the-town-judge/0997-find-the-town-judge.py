class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if len(trust) == 0:
            return n if n is 1 else -1
        balance = [0] * (n + 1)
        for t in trust:
            balance[t[0]] -= 1
            balance[t[1]] += 1
        for i in range (0, n + 1):
            if balance[i] == n - 1:
                return i
        return -1