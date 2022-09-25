class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElem = *max_element(begin(nums), end(nums));
        int longest = 0, length = 0;
        for(int i = 0; i < size(nums); ++i) {
            if(nums[i] == maxElem) {
                length++;
                longest = max(longest, length);
            } else length = 0;
        }
        return longest;
    }
};