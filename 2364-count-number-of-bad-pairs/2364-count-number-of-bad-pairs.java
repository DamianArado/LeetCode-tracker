class Solution {
    public long countBadPairs(int[] nums) {
        long n = nums.length, valid = 0;
        var mp = new HashMap<Integer, Integer>();
        for(int i = 0; i < n; ++i) {
            if(mp.containsKey(i - nums[i])) valid += mp.get(i - nums[i]);
            mp.put(i - nums[i], mp.getOrDefault(i - nums[i], 0) + 1);
        }
        long total = n * (n - 1) / 2;
        return total - valid;
    }
}