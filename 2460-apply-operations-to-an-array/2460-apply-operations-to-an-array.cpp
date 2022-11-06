class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = size(nums);
        for(int i = 0; i < n - 1; ++i) {
            if(nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int j = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                ++j;
            }
        }
        return nums;
    }
};