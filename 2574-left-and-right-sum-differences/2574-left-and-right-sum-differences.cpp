class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = size(nums), sum = 0;
        if(n == 1) return {0};
        vector<int> ans(n);
        ans[0] = 0;
        for(int i = 1; i < n; ++i) {
            sum += nums[i - 1];
            ans[i] = sum;
        }
        sum = 0;
        for(int i = n - 2; i >= 0; --i) {
            sum += nums[i + 1];
            ans[i] = abs(ans[i] - sum);
        }
        return ans;
    }
};