class Solution {
public:
    // brute forced it :XD
    long long subArrayRanges(vector<int>& nums) {
        int n = size(nums);
        if(n == 1) return 0;
        if(n == 2) return nums[0] > nums[1] ? nums[0] - nums[1] : nums[1] - nums[0];
        
        long long ans = 0;
        // consider all subarrays
        for(int i = 0; i < n - 1; ++i) {
            int currentMax = max(nums[i], nums[i + 1]), currentMin = min(nums[i], nums[i + 1]);
            long long currentSum = 0;
            for(int j = i + 1; j < n; ++j) {
                currentMin = min(currentMin, nums[j]);
                currentMax = max(currentMax, nums[j]);
                currentSum += currentMax - currentMin;
            }
            ans += currentSum;
        }
        return ans;
    }
};