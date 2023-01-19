class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int ans = 0, runningSum = 0;
        int[] count = new int[k];
        count[0] = 1;
        for(int num : nums) {
            runningSum = (runningSum + num) % k;
            if(runningSum < 0) runningSum += k;
            ans += count[runningSum]++;
        }
        return ans;
    }
}