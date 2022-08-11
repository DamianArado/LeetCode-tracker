class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        int n = nums.size();
        
        // Step 1: sort the array
        sort(nums.begin(), nums.end());
        
        // Step 2: i will go from index 0 to n - 3, j will start at i + 1 and will go till k - 1 
        // and k starts at n - 1 in our 2-pointer based approach
        for(int i = 0; i < n - 2; ++i) {
            // since not possible to get a triplet further
            if(nums[i] > 0) return triplets;
            // just to keep a check on the duplicates of i
            if(i == 0 or (i > 0 and nums[i] != nums[i - 1])) {
                int j = i + 1, k = n - 1, reqSum = -nums[i];
                while(j < k) {
                    if(nums[j] + nums[k] == reqSum) {
                        triplets.push_back({ nums[i], nums[j], nums[k] });
                        // check duplicates here as well
                        while(j < k and nums[j] == nums[j + 1]) ++j;
                        while(j < k and nums[k] == nums[k - 1]) --k;
                        ++j;
                        --k;
                    } 
                    // move the 2 pointers accordingly
                    else if(nums[j] + nums[k] > reqSum) --k;
                    else ++j;
                }
            }
        }
        return triplets;
    }
};