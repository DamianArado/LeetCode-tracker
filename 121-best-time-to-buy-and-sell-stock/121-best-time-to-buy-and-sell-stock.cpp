class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = size(prices), profit = 0, minBuy = prices[0];
        for(int &price : prices) {
            int sellingPrice = price - minBuy;
            profit = max(profit, sellingPrice);
            minBuy = min(minBuy, price);
        }
        return profit;
    }
};