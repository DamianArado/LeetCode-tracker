class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = size(nums), target = accumulate(begin(nums), end(nums), 0);
        if ((target -= x) == 0) 
            return n;
        int currentSum = 0, maxLength = 0, left = 0;
        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];
            while (left <= right and currentSum > target) 
                currentSum -= nums[left++];
            if (currentSum == target)
                maxLength = max(maxLength, right - left + 1);
        }
        return maxLength ? n - maxLength : -1;
    }
};