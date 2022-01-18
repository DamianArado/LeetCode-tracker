class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, j;
        // first index i such that arr[i] < arr[i + 1]
        for(i = n - 2; i >= 0; --i) {
            if(nums[i] < nums[i + 1]) break;
        }
        // if we got an edge case where there is no such i, for ex. [5,4,3,2,1]
        // reverse the last permutation -> first permutation
        if(i < 0) reverse(nums.begin(), nums.end());
        // second index j such that arr[j] > arr[i]
        else {
            for(j = n - 1; j >= i; --j) {
                if(nums[j] > nums[i]) break;
            }
            // swap arr[i] and arr[j]
            swap(nums[i], nums[j]);
            // reverse arr[i + 1 : last]
            reverse(nums.begin() + i + 1, nums.end());
        }
     }
};