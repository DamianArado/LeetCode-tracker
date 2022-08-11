class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        int[] count = new int[201];
        int result = 0;
        for(int num : nums) {
            if(num >= 2 * diff)
                if(count[num - diff] == 1 && count[num - 2 * diff] == 1)
                    ++result;
            count[num] = 1;
        }
        return result;
    }
}