class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(begin(nums), end(nums));
        int freqMaxElem = 0;
        long long count = 0;
        for (int i = 0, j = 0; j < size(nums); ++j) {
            if (nums[j] == maxElement) 
                ++freqMaxElem;
            while (freqMaxElem >= k and i <= j) {
                if (nums[i] == maxElement)
                    --freqMaxElem;
                ++i;
            }
            count += i;
        }
        return count;
    }
};