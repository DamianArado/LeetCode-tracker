class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), apparentSum = 0;
        int realSum = n * (n + 1) / 2;
        for(int num : nums) apparentSum += num;
        return realSum - apparentSum;
    }
};