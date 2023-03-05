class Solution {
    public int maxProfit(int[] prices) {
        int minBuy = prices[0], ans = 0;
        for(int price : prices) {
            ans = Math.max(ans, price - minBuy);
            minBuy = Math.min(minBuy, price);
        }
        return ans;
    }
}