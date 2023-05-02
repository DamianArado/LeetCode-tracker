class Solution {
    public int arraySign(int[] nums) {
        int product = 1;
        for(int num : nums) 
            product *= (num != 0 ? (num > 0 ? 1 : -1) : 0);
        return product == 0 ? 0 : (product > 0 ? 1 : -1);
    }
}