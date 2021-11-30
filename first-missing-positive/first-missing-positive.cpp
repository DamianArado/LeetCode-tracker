class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long int firstMissingPosInt = 1;
        for(int i = 0; i<nums.size(); i++) {
            if(firstMissingPosInt == nums[i])
                firstMissingPosInt++;
        }
        return firstMissingPosInt;
    }
};