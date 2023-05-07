class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, ans = 0, len = 0, n = size(nums);
        while(i < n) {
            if(nums[i] == 1) {
                len = 1;
                while(i < n - 1 and nums[i + 1] == 1) {
                    len++;
                    i++;
                }
                ans = max(ans, len);
            }
            ++i;
        }
        return ans;
    }
};