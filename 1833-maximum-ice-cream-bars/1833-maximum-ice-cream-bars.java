class Solution {
    public int maxIceCream(int[] costs, int coins) {
        if(costs.length == 1) return (costs[0] <= coins ? 1 : 0);
        Arrays.sort(costs);
        int iceCream = 0, i = 0;
        while(i < costs.length && coins >= costs[i]) {
            coins -= costs[i];
            ++i;
            ++iceCream;
        }
        return iceCream;
    }
}