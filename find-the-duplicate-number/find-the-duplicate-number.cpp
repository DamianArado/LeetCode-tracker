class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // edge case
        if(n == 2)
            return 1;
        
        sort(nums.begin(), nums.end());
        
        int duplicate = 0;
        
        for(int i = 1; i<nums.size(); i++) {
            
            // if two consecutive elements are same
            if(nums[i] == nums[i-1]) 
                duplicate = nums[i];
        }
        return duplicate;
    }
};