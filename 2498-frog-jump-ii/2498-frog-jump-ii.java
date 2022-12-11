class Solution {
    public int maxJump(int[] stones) {
        int maxDiff = stones[1] - stones[0], n = stones.length;
        for(int i = 2; i < n; i += 2) maxDiff = Math.max(maxDiff, stones[i] - stones[i - 2]);
        for(int i = 3; i < n; i += 2) maxDiff = Math.max(maxDiff, stones[i] - stones[i - 2]);
        return maxDiff;
    }
}