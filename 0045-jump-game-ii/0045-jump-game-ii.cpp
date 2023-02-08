class Solution {
public:
    int jump(vector<int>& nums) {
        int n = size(nums), curFarthest = 0, curEnd = 0, jumps = 0;
        for(int i = 0; i < n - 1; ++i) {
            curFarthest = max(curFarthest, i + nums[i]);
            // moving level-by-level
            if(i == curEnd) {
                ++jumps;
                curEnd = curFarthest;
            }
        }
        return jumps;
    }
};