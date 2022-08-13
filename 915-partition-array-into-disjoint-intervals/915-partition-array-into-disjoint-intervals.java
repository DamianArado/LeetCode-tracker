class Solution {
    public int partitionDisjoint(int[] nums) {
        int maxUntilNow = nums[0], leftPartMax = nums[0], partIdx = 0;
        for(int i = 0; i < nums.length; ++i) {
            maxUntilNow = Math.max(maxUntilNow, nums[i]);
            if(nums[i] < leftPartMax) {
                leftPartMax = maxUntilNow;
                partIdx = i;
            }
        }
        return partIdx + 1;
    }
}