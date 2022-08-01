class Solution {
    private static int houseRob(int[] nums, int start, int end) {
        int prev2 = 0, prev = nums[start];
        for(int idx = start + 1; idx <= end; ++idx) {
            int current = Math.max(nums[idx] + prev2, prev);
            prev2 = prev;
            prev = current;
        }
        return prev;
    }
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        return Math.max(houseRob(nums, 0, n - 2), houseRob(nums, 1, n - 1));
    }
}