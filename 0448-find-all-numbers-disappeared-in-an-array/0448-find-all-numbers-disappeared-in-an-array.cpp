class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < size(nums); ++i)
            while(nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        for(int i = 0; i < size(nums); ++i)
            if(nums[i] != i + 1)
                ans.emplace_back(i + 1);
        return ans;
    }
};