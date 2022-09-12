class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = size(nums);
        vector<int> ans(n);
        int i = 0, j = n - 1;
        for(int ptr = n - 1; ptr >= 0; --ptr) {
            if(abs(nums[j]) > abs(nums[i])) {
                ans[ptr] = nums[j] * nums[j];
                --j;
            } else {
                ans[ptr] = nums[i] * nums[i];
                ++i;
            }
        }
        return ans;
    }
};