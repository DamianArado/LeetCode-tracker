class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int i = 0, idx = 0; i < size(nums); ++i) {
            if (nums[i] % 2 == 0)
                swap(nums[idx++], nums[i]);
        }
        return nums;
    }
};