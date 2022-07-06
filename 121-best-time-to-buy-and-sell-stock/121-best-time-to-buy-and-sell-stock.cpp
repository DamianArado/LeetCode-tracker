class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // to sell a stock at the i-th day we need minimum available price till the (i - 1)-th day
        int minBuy = prices[0], maxSell = 0;
        for(int price : prices) {
            int sellingPrice = price - minBuy;
            maxSell = max(maxSell, sellingPrice);
            minBuy = min(minBuy, price);
        }
        return maxSell;
    }
};