class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0, sum = 0;
        unordered_set<int> seen;
        int i = 0; 
        for(int j = 0; j < size(nums); ++j) {
            while(i < j and (seen.count(nums[j]) or size(seen) >= k)) {
                sum -= nums[i];
                seen.erase(nums[i]);
                ++i;
            }
            sum += nums[j];
            seen.insert(nums[j]);
            if(size(seen) == k)
                maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};