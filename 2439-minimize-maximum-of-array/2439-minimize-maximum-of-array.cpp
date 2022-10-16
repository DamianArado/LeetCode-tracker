class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum = 0, ans = 0;
        for(int i = 0; i < size(nums); ++i) {
            sum += nums[i];
            ans = max(ans, (sum + i) / (i + 1));
        }
        return ans;
    }
};