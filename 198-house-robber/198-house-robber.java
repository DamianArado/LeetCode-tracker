class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        int prev2 = 0, prev = nums[0];
        for(int idx = 1; idx < n; ++idx) {
            int current = Math.max(nums[idx] + prev2, prev);
            prev2 = prev;
            prev = current;
        }
        return prev;
    }
}