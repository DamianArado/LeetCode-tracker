class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int i = 0, ans = 0, len = 0, n = nums.length;
        while(i < n) {
            if(nums[i] == 1) {
                len = 1;
                while(i < n - 1 && nums[i + 1] == 1) {
                    len++;
                    i++;
                }
                ans = Math.max(ans, len);
            }
            ++i;
        }
        return ans;
    }
}