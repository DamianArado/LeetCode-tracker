class Solution {
public:
    bool canJump(vector<int>& nums) {
        // maintain the max distance reached from that index
        int maxDistance = 0, n = size(nums);
        for(int i = 0; i <= maxDistance; ++i) {
            maxDistance = max(maxDistance, i + nums[i]);
            if(maxDistance >= n - 1)
                return true;
        }
        return false;
    }
};