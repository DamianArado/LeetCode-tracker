class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxLength = 0;
        unordered_map<int, int> freq;
        for (int i = 0, j = 0; j < size(nums); ++j) {
            freq[nums[j]]++;
            if (freq[nums[j]] > k) {
                while (freq[nums[j]] > k) {
                    --freq[nums[i]];
                    ++i;
                }
            }
            maxLength = max(maxLength, j - i + 1);
        }
        return maxLength;
    }
};