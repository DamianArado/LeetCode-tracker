class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, currentSum = 0;
        for(int i = 0; i < size(nums); ++i) {
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);
            if(currentSum < 0) currentSum = 0;
        }
        return maxSum;
    }
};