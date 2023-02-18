class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = size(nums);
        sort(begin(nums), end(nums));
        // just minimize the high score as low score is always 0
        return min({nums[n - 1] - nums[2], nums[n - 2] - nums[1], nums[n - 3] - nums[0]}); 
    }
};