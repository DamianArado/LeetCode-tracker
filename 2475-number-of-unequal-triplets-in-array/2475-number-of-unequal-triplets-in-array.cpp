class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n = size(nums), count = 0;
        for(int i = 0; i < n - 2; ++i) {
            for(int j = i + 1; j < n - 1; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    if(nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) 
                        count++;
                }
            }
        }
        return count;
    }
};