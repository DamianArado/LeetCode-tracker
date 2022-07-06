class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minBuy = prices[0]
        maxSell = 0
        for price in prices:
            sellingPrice = price - minBuy
            maxSell = max(maxSell, sellingPrice)
            minBuy = min(minBuy, price)
        return maxSell