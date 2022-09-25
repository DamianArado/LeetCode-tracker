class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = size(nums);
        vector<int> increasing(n, 1), decreasing(n, 1), ans;
        for(int i = 1, j = n - 2; i < n - 1, j >= 0; ++i, --j) {
            if(nums[i] <=  nums[i - 1])
                decreasing[i] = 1 + decreasing[i - 1];
            if(nums[j] <= nums[j + 1])
                increasing[j] = 1 + increasing[j + 1];
        }
        for(int i = k; i < n - k; ++i) 
            if(increasing[i + 1] >= k and decreasing[i - 1] >= k)
                ans.emplace_back(i);
        return ans;
    }
};