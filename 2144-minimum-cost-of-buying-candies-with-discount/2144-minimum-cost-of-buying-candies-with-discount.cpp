class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int minCost = 0, n = cost.size(), mult = 0;
        sort(cost.begin(), cost.end());
        for(int i = n - 1; i >= 0; --i) {
            if(mult == 2) mult = 0;
            else if(mult < 2) {
                minCost += cost[i];
                ++mult;
            }
        }
        return minCost;
    }
};