class Solution {
    public long minimumMoney(int[][] transactions) {
        long minMoney = 0; int minTransTillNow = 0;
        for(int[] transaction : transactions) {
            minTransTillNow = Math.max(minTransTillNow, Math.min(transaction[0], transaction[1]));
            minMoney += Math.max(transaction[0] - transaction[1], 0);
        }
        return minTransTillNow + minMoney;
    }
}