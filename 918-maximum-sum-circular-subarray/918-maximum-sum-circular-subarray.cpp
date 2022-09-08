class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, minSum = nums[0], maxSum = nums[0], currentMin = 0, currentMax = 0;
        for(int &num : nums) {
            total += num;
            currentMin = min(currentMin + num, num);
            minSum = min(minSum, currentMin);
            currentMax = max(currentMax + num, num);
            maxSum = max(maxSum, currentMax);
        }
        return maxSum < 0 ? maxSum : max(maxSum, total - minSum);
    }
};