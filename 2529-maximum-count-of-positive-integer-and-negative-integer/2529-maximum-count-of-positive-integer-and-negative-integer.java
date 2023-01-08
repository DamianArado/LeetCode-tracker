class Solution {
    public int maximumCount(int[] nums) {
        int cntPlus = 0, cntNeg = 0;
        for(int num : nums) {
            if(num < 0) cntNeg++;
            else if(num > 0) cntPlus++;
        }
        return Math.max(cntPlus, cntNeg);
    }
}