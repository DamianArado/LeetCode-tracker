class Solution {
    public int singleNumber(int[] nums) {
        int singleOne = 0;
        for(int num : nums) singleOne ^= num;
        return singleOne;
    }
}