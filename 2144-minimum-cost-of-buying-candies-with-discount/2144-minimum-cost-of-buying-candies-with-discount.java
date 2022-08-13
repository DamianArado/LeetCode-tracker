class Solution {
    public int minimumCost(int[] cost) {
        int minCost = 0, n = cost.length, mult = 0;
        Arrays.sort(cost);
        for(int i = n - 1; i >= 0; --i) {
            if(mult == 2) mult = 0;
            else if(mult < 2) {
                minCost += cost[i];
                ++mult;
            }
        }
        return minCost;
    }
}