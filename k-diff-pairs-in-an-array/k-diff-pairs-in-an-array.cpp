class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        if(nums.size() == 1) return 0;
        
        int kDiffPairs = 0;
        for(int i = 0, j = 0; i<nums.size(); i++) {
            
            for(j = max(j,i+1); j<nums.size() && (long) nums[j] - nums[i]<k; j++);
            
            if (j < nums.size() && (long) nums[j] - nums[i] == k) 
                kDiffPairs++;
            
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) 
                i++;
        }
        return kDiffPairs;
    }
};