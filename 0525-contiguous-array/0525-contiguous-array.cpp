// Convert all the 0s in array to -1. Now if an array has equal 0s and 1, the sum will be 0. Use unordered map to check 
// if you encountered the same sum before. If you did it means all the elements between the last time you encountered 
// the sum and now add up to zero, i.e. you have equal 0s and 1s. Keep updating result accordingly.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) 
            if(nums[i] == 0) 
                nums[i] = -1;
        
        unordered_map<int,int> mp;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == 0) 
                ans = i + 1;
            else if (!mp.count(sum)) 
                mp[sum] = i;
            else 
                ans = max(ans, i - mp[sum]);
        }
        return ans;
    }
};