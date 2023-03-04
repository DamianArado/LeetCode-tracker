class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        long count = 0;
        int lastMinIdx = -1, lastMaxIdx = -1, subArrStart = 0;
        for(int i = 0; i < nums.length; ++i) {
            if(nums[i] < minK || nums[i] > maxK) {
                lastMinIdx = lastMaxIdx = -1;
                subArrStart = i + 1;
            }
            if(nums[i] == minK) lastMinIdx = i;
            if(nums[i] == maxK) lastMaxIdx = i;
            count += Math.max(0, Math.min(lastMinIdx, lastMaxIdx) - subArrStart + 1);
        }
        return count;
    }
}