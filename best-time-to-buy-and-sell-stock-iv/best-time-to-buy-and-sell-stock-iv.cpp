class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int maxProfit=0;
        
        if(prices.size()<2)
            return 0;
        
        if(k>prices.size()/2){
            for(int i=1; i<prices.size(); i++)
                maxProfit += max(prices[i]-prices[i-1], 0);
            return maxProfit;
        }
        
        int hold[k+1];
        int release[k+1];
        
        for (int i=0;i<=k;++i){
            hold[i] = INT_MAX;
            release[i] = 0;
        }
        
        for(int i=0; i<prices.size(); i++){
            for(int j=k; j>=1; j--){
                release[j] = max(release[j], prices[i] - hold[j]);
                hold[j] = min(hold[j], prices[i] - release[j-1]);
                maxProfit = max(maxProfit, release[j]);
            }
        }
        return maxProfit;
    }
};