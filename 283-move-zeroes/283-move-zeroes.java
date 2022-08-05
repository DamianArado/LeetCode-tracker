class Solution {
    public void moveZeroes(int[] nums) {
        int zeroes = 0, n = nums.length;
        for(int num : nums)
            if(num == 0) zeroes++;
        int nonZeroes = n - zeroes;
        
        int eIdx = 0;
        for(int i = 0; i < n; ++i) 
            if(nums[i] != 0) nums[eIdx++] = nums[i];
        while(eIdx < n) 
            nums[eIdx++] = 0;
    }
}