class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int lastMinIdx = -1, lastMaxIdx = -1, subArrStartIdx = 0;
        
        for(int i = 0; i < size(nums); ++i) {
            // invalid element, hence start fresh with new starting index of subarrays
            if(nums[i] < minK or nums[i] > maxK) {
                lastMinIdx = lastMaxIdx = -1;
                subArrStartIdx = i + 1;
            }
            // update the indices where we get our minK & maxK
            if(nums[i] == minK) lastMinIdx = i;
            if(nums[i] == maxK) lastMaxIdx = i;
            
            // the subarray ends at nums[i]
            // and starts in the range: [subArrStartIdx, min(lastMinIdx, lastMaxIdx)]
            // thus, we have min(lastMinIdx, lastMaxIdx) - subArrStartIdx + 1 choices 
            // until we find an invalid element
            ans += max(0, min(lastMinIdx, lastMaxIdx) - subArrStartIdx + 1);
        }
        return ans;
    }
};