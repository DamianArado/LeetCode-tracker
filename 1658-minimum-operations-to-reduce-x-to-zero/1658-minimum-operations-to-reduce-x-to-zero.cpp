class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // to find the minimum operations to reduce x to zero using elements in nums
        // we can use the result of the longest subarray with sum k inside nums where k = sum of elements - x
        int n = nums.size(), sum = 0;
        for(int num : nums) sum += num;
        
        int k = sum - x, currentSum = 0, longestSubArr = 0;
        if(k == 0) return n;
        // the 2 pointers we will use in this variable sliding window: i <= j
        int i = 0;
        for(int j = 0; j < n; ++j) {
            currentSum += nums[j];
            if(currentSum > k)
                while(currentSum > k and i <= j) {
                    currentSum -= nums[i];
                    i++;
                }
            if(currentSum == k)
                longestSubArr = max(longestSubArr, j - i + 1);
        }
        // shortest subarray with sum = x is n - longest subarray with sum = sum - x
        return longestSubArr == 0 ? -1 : n - longestSubArr;
    }
};