class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int iceCream = 0, i = 0;
        while(i < size(costs) and coins >= costs[i]) {
            coins -= costs[i];
            ++i;
            ++iceCream;
        }
        return iceCream;
    }
};