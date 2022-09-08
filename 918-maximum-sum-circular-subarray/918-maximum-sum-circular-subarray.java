class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int total = 0, currentMin = 0, currentMax = 0, minSum = nums[0], maxSum = nums[0];
        for(int num : nums) {
            total += num;
            currentMin = Math.min(currentMin + num, num);
            minSum = Math.min(minSum, currentMin);
            currentMax = Math.max(currentMax + num, num);
            maxSum = Math.max(maxSum, currentMax);
        }
        return maxSum < 0 ? maxSum : Math.max(maxSum, total - minSum);
    }
}