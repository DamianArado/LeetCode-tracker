class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length, apparentSum = 0;
        int realSum = n * (n + 1) / 2;
        for(int num : nums) apparentSum += num;
        return realSum - apparentSum;
    }
}