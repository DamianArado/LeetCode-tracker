class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int count = 1, left = 0;
        for(int right = 0; right < size(nums); ++right) {
            if(nums[right] - nums[left] > k) {
                ++count;
                left = right;
            }
        }
        return count;
    }
};