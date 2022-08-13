class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n = nums.size(), minDiff = INT_MAX;
        
        vector<vector<int>> minDiffPairs;
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < n; ++i) 
            minDiff = min(minDiff, nums[i] - nums[i - 1]);
        
        for(int i = 1; i < n; ++i)
            if(nums[i] - nums[i - 1] == minDiff)
                minDiffPairs.push_back({nums[i - 1], nums[i]});
        
        return minDiffPairs;
    }
};