class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        if(n < 2) return false;
        var mp = new HashMap<Integer, Integer>();
        mp.put(0, -1);
        int runningSum = 0;
        for(int i = 0; i < n; ++i) {
            runningSum += nums[i];
            runningSum %= k;
            if(mp.containsKey(runningSum)) {
                if(i - mp.get(runningSum) > 1)
                    return true;
            } else mp.put(runningSum, i);
        }
        return false;
    }
}