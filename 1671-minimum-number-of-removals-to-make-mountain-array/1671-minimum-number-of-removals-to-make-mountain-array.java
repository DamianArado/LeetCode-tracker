class Solution {
    public int minimumMountainRemovals(int[] nums) {
        int n = nums.length, maxBitonic = 0;
        int[] lis = new int[n];
        int[] lds = new int[n];
        for(int idx = 0; idx < n; ++idx) {
            lis[idx] = 1;
            lds[idx] = 1;
        }
        for(int idx = 1; idx < n; ++idx)
            for(int prev = 0; prev < idx; ++prev)
                if(nums[prev] < nums[idx] && lis[prev] + 1 > lis[idx])
                    lis[idx] = lis[prev] + 1;
        for(int idx = n - 2; idx >= 0; --idx)
            for(int prev = n - 1; prev > idx; --prev)
                if(nums[prev] < nums[idx] && lds[prev] + 1 > lds[idx])
                    lds[idx] = lds[prev] + 1;
        for(int idx = 0; idx < n; ++idx)
            if(lds[idx] > 1 && lis[idx] > 1)
                maxBitonic = Math.max(maxBitonic, lds[idx] + lis[idx] - 1);
        return (n - maxBitonic);
    }
}