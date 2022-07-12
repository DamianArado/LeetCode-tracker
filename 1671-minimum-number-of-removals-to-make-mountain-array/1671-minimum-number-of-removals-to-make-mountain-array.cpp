class Solution {
public:
    // TC: O(n^2) SC: O(n)
    int minimumMountainRemovals(vector<int>& nums) {
        // We will first try to find out the length of the longest bitonic subsequence in nums
        // This will help us to find the minimum removals out of nums to make it a mountain array
        int n = nums.size(), maxBitonicLen = 0;
        vector<int> lis(n, 1), lds(n, 1);
        
        // STEP 1
        // traverse from the front to calculate the length of the longest increasing subsequence
        for(int idx = 1; idx < n; ++idx) {
            for(int prev = 0; prev < idx; ++prev) {
                if(nums[prev] < nums[idx] and lis[prev] + 1 > lis[idx])
                    lis[idx] = lis[prev] + 1;
            }
        }
        
        // STEP 2
        // traverse from the back to calculate the length of the longest decreasing subsequence (as seen from the front)
        for(int idx = n - 2; idx >= 0; --idx) {
            for(int prev = n - 1; prev > idx; --prev) {
                if(nums[prev] < nums[idx] and lds[prev] + 1 > lds[idx])
                    lds[idx] = lds[prev] + 1;
            }
        }
        
        // STEP 3
        // traverse lis and lds and calculate the longest bitonic subsequence length
        // make sure we have lis[i] > 1 and lds[i] > 1 in order to satisfy the properties of mountain array
        // [0 .... idx .... n - 1] is the position of index in the mountain array
        for(int idx = 0; idx < n; ++idx)
            // idx should not be 0 or n - 1 that's why this check is mandatory
            if(lis[idx] > 1 and lds[idx] > 1)
                maxBitonicLen = max(maxBitonicLen, lis[idx] + lds[idx] - 1);
        
        // return the minimum no. of removals needed to make it the longest bitonic subsequence
        return n - maxBitonicLen;
    }
};