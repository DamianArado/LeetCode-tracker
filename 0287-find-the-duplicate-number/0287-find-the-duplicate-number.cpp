class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int &num : nums) {
            int idx = abs(num);
            if(nums[idx] < 0) return idx;
            nums[idx] = -nums[idx];
        }
        return -1;
    }
};