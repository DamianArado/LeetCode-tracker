class Solution {
    private static int maxRob(int[] nums, int l, int r) {
        int prev2 = 0, prev = nums[l];
        for(int i = l + 1; i < r; ++i) {
            int pick = nums[i] + prev2;
            int dontPick = prev;
            int currentMax = Math.max(pick, dontPick);
            prev2 = prev;
            prev = currentMax;
        }
        return prev;
    }
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        return Math.max(maxRob(nums, 0, n - 1), maxRob(nums, 1, n));
    }
}