class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = size(nums);
        vector<vector<int>> ans;
        if(n < 4) return ans;
        sort(begin(nums), end(nums));
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                double new_target = (double) target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;
                while(left < right) {
                    if(nums[left] + nums[right] == new_target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        while(left < right and nums[left] == nums[left - 1]) ++left;  // duplicates
                    } 
                    else if(nums[left] + nums[right] > new_target) --right;
                    else ++left;
                }
                while(j + 1 < n and nums[j] == nums[j + 1]) ++j; // duplicates
            }
            while(i + 1 < n and nums[i] == nums[i + 1]) ++i;  // duplicates
        }
        return ans;
    }
};