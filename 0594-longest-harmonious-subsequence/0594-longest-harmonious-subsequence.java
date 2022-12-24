class Solution {
    public int findLHS(int[] nums) {
        int maxLen = 0;
        var dp = new HashMap<Integer, Integer>();
        for(int num : nums) {
            dp.put(num, 1 + dp.getOrDefault(num, 0));
            if(dp.containsKey(num - 1))
                maxLen = Math.max(maxLen, dp.get(num) + dp.get(num - 1));
            if(dp.containsKey(num + 1))
                maxLen = Math.max(maxLen, dp.get(num) + dp.get(num + 1));
        }
        return maxLen;
    }
}