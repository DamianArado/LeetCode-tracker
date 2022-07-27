class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), currentSum = 0, minSubArr = INT_MAX;
        int i = 0;
        for(int j = 0; j < n; ++j) {
            currentSum += nums[j];
            while(currentSum >= target) {
                minSubArr = min(minSubArr, j - i + 1);
                currentSum -= nums[i];
                i++;
            }
        }
        return minSubArr == INT_MAX ? 0 : minSubArr; 
    }
};