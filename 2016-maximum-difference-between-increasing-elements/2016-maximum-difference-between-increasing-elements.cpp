class Solution {
public:
    int maximumDifference(vector<int>& prices) {
        int n = size(prices), profit = -1, minBuy = prices[0];
        for(int &price : prices) {
            int sellingPrice = price - minBuy;
            profit = max(profit, sellingPrice);
            minBuy = min(minBuy, price);
        }
        return profit == 0 ? -1 : profit;
    }
};