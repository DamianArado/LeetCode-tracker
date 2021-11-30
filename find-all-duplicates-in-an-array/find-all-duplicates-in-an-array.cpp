class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> duplicates;
        
        // edge case
        if(nums.size() == 1)
            return duplicates;
        
        for(int i = 1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                duplicates.emplace_back(nums[i]);
            }
        }
        return duplicates;
    }
};