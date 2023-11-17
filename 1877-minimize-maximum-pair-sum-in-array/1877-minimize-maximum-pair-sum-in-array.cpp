class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = size(nums), left = 0, right = n - 1, ans = 0;
        while (left < right) {
            ans = max(ans, nums[left] + nums[right]);
            ++left, --right;
        }
        return ans;
    }
};