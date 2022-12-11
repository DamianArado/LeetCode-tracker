class Solution {
    public int longestSquareStreak(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        var dp = new HashMap<Integer, Integer>();
        for(int num : nums) {
            int sqr = (int) Math.sqrt(num);
            if(sqr * sqr == num)
                dp.put(num, 1 + dp.getOrDefault(sqr, 0));
            else dp.put(num, 1);
            ans = Math.max(ans, dp.get(num));
        }
        return ans > 1 ? ans : -1;
    }
}