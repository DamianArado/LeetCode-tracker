class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxTotalProfit = 0;
        
        // O(n) auxiliary space
        vector<int> firstBuySellProfits(prices.size(), 0); 
        
        int minPriceSoFar = numeric_limits<int>::max();
        
        // Forward phase: For each day, we record maximum profit
        // if we sell on that day
        for(int i = 0; i<prices.size(); ++i) {
            minPriceSoFar = min(minPriceSoFar, prices[i]);
            maxTotalProfit = max(maxTotalProfit, prices[i] - minPriceSoFar);
            firstBuySellProfits[i] = maxTotalProfit;
        }
        
        // Backward phase: For each day, find the maximum profit 
        // if we make the second buy on that day
        int maxPriceSoFar = numeric_limits<int>::min();
        for(int i = prices.size() - 1; i>0; --i) {
            maxPriceSoFar = max(maxPriceSoFar, prices[i]);
            maxTotalProfit = max(maxTotalProfit, maxPriceSoFar - prices[i] + firstBuySellProfits[i-1]);
        }
        return maxTotalProfit;
    }
};