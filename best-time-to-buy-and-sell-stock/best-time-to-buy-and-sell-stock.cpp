class Solution {
public:
    int maxProfit(vector<int> &prices) {
    int maximizedProfit = 0;
    int minPrice = INT_MAX;
        
    for(int i = 0; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        maximizedProfit = max(maximizedProfit, prices[i] - minPrice);
    }
        
    return maximizedProfit;
    }
};