class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length, currentSum = 0, minSubArr = Integer.MAX_VALUE;
        int i = 0;
        for(int j = 0; j < n; ++j) {
            currentSum += nums[j];
            while(currentSum >= target) {
                minSubArr = Math.min(minSubArr, j - i + 1);
                currentSum -= nums[i];
                i++;
            }
        }
        return minSubArr == Integer.MAX_VALUE ? 0 : minSubArr;
    }
}