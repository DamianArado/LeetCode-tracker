class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        int[] hash = new int[n];
        for(int i = 0; i < n; ++i) {
            dp[i] = 1;
            hash[i] = i;
        }
        Arrays.sort(nums);
        int maxLIS = 1, lastIdx = 0;
        
        for(int idx = 1; idx < n; ++idx) {
            for(int prev = 0; prev < idx; ++prev) {
                if(nums[idx] % nums[prev] == 0 && dp[idx] < 1 + dp[prev]) {
                    dp[idx] = 1 + dp[prev];
                    hash[idx] = prev;
                }
            }
            if(dp[idx] > maxLIS) {
                maxLIS = dp[idx];
                lastIdx = idx;
            }
        }
        
        List<Integer> lds = new ArrayList<Integer>();
        lds.add(nums[lastIdx]);
        while(lastIdx != hash[lastIdx]) {
            lastIdx = hash[lastIdx];
            lds.add(nums[lastIdx]);
        }
        Collections.reverse(lds);
        return lds;
    }
}