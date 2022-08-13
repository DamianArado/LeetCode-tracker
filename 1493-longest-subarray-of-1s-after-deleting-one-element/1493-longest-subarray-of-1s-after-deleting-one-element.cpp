class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // at most k zeroes can be flipped algo using sliding window
        int k = 1, i = 0, j;
        for(j = 0; j < nums.size(); ++j) {
            if(nums[j] == 0) --k;
            if(k < 0 and nums[i++] == 0) ++k;
        }
        return j - i - 1;
    }
};