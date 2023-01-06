class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        if(size(costs) == 1) return (costs[0] <= coins ? 1 : 0);
        sort(begin(costs), end(costs));
        int iceCream = 0, i = 0;
        while(coins >= costs[i] and i < size(costs)) {
            coins -= costs[i];
            ++i;
            ++iceCream;
        }
        return iceCream;
    }
};