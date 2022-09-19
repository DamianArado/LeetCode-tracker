class Solution:
    def minimumMoney(self, transactions: List[List[int]]) -> int:
        minTransTillNow, minMoney = 0, 0
        for transaction in transactions:
            minTransTillNow = max(minTransTillNow, min(transaction[0], transaction[1]))
            minMoney += max(transaction[0] - transaction[1], 0)
        return minTransTillNow + minMoney