class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // step1: put all the elements in the correct places
        int n = size(nums);
        for(int i = 0; i < n; ++i)
            while(nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        // step2: check the first element which is not in order
        for(int i = 0; i < n; ++i)
            if(nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};