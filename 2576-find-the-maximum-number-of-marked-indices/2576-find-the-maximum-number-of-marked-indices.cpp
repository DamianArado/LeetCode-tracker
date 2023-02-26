class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int left = 0, right = (size(nums) + 1) / 2;
        for(; right < size(nums); ++right)
            if(nums[left] * 2 <= nums[right]) ++left;
        return left * 2;
    }
};