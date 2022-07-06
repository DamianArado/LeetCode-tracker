class Solution {
    public int maxProfit(int[] prices) {
        int minBuy = prices[0], maxSell = 0;
        for(int price : prices) {
            int sellingPrice = price - minBuy;
            maxSell = Math.max(maxSell, sellingPrice);
            minBuy = Math.min(minBuy, price);
        }
        return maxSell;
    }
}