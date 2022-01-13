class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int nos = 0; nos < (1 << nums.size()); ++nos) {
            vector<int> subset;
            for(int j = 0; j < nums.size(); ++j) 
                if(nos & (1 << j)) subset.emplace_back(nums[j]);
            ans.emplace_back(subset);
        }
        return ans;
    }
};