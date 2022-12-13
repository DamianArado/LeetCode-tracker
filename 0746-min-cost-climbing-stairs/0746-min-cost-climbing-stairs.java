class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int pprev = cost[0], prev = cost[1];
        for(int i = 2; i < n; ++i) {
            int current = cost[i] + Math.min(pprev, prev);
            pprev = prev;
            prev = current;
        }
        return Math.min(pprev, prev);
    }
}