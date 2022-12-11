class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        int ans = 0;
        var dp = new HashMap<Integer, Integer>();
        for(int i : arr) {
            if(dp.containsKey(i - difference))
                dp.put(i, 1 + dp.get(i - difference));
            else 
                dp.put(i, 1);
            ans = Math.max(ans, dp.get(i));
        }
        return ans;
    }
}