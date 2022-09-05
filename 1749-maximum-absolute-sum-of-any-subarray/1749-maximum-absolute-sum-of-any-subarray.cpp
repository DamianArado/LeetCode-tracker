class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, maxSum = 0, minSum = 0;
        for(int num : nums) {
            sum += num;
            maxSum = max(maxSum, sum);
            minSum = min(minSum, sum);
        }
        return maxSum - minSum;
    }
};