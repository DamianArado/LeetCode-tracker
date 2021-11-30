class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        /* 
        NlogN solution
        // Sort this first
        sort(nums.begin(), nums.end());
        
        int seqLen = 1;
        int maxLen = 1;
        
        for(int i = 1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]+1) {
                seqLen++;
            } else if(nums[i] == nums[i-1]) {
                // Same numbers in sequence, we'll skip them
                continue;
            } else {
                seqLen = 1;
            }
            maxLen = max(seqLen, maxLen);
        }
        return maxLen;
        */
        
        // Unordered set based approach - O(N) 
        
        unordered_set<int> box;
        
        // edge case
        if(nums.size() == 0)
            return 0;
        
        long int ans = 1;
        
        // Insert all integers inside the unordered set 
        for(int i = 0; i<nums.size(); i++) {
            box.insert(nums[i]);
        }
        
        for(int i = 0; i<nums.size(); i++) {
            long int start = nums[i];
            
            if(box.find(start-1) != box.end())
                continue;
            
            while(box.find(start) != box.end())
                start++;
            
            ans = max(ans,(start-nums[i]));
        }
        return ans;
    }
};