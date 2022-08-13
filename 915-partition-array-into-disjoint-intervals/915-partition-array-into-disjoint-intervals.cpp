class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int maxUntilNow = nums[0], leftPartMax = nums[0], partIdx = 0;
        for(int i = 1; i < nums.size(); ++i) {
            maxUntilNow = max(maxUntilNow, nums[i]);
            if(nums[i] < leftPartMax) {
                leftPartMax = maxUntilNow;
                partIdx = i;
            }
        }
        return partIdx + 1;
    }
};