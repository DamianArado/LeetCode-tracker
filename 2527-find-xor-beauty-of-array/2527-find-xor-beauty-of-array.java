class Solution {
    public int xorBeauty(int[] nums) {
        int xored = ((nums[0] | nums[0]) & nums[0]);
        int n = nums.length;
        if(n == 1) return xored;
        for(int i = 1; i < n; ++i)
            xored ^= nums[i];
        return xored;
    }
}