class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        // divide 3n elements into n, n, n elements such that the diff of elements of any 2 is min
        // needs a dry-run for proper understanding
        int n = size(nums) / 3;
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        long long leftSum = 0, rightSum = 0;
        vector<long long> minLeft(3*n);
        
        for(int i = 0; i < n; ++i) {
            left.emplace(nums[i]);
            leftSum += nums[i];
        }
        minLeft[n - 1] = leftSum;
        
        for(int i = n; i < 2*n; ++i) {
            leftSum += nums[i];
            left.emplace(nums[i]);
            leftSum -= left.top();
            left.pop();
            minLeft[i] = leftSum;
        }
        
        for(int i = 3*n - 1; i >= 2*n; --i) {
            rightSum += nums[i];
            right.emplace(nums[i]);
        }
        long long result = minLeft[2*n - 1] - rightSum;
        
        for(int i = 2*n - 1; i >= n; --i) {
            rightSum += nums[i];
            right.emplace(nums[i]);
            rightSum -= right.top();
            right.pop();
            result = min(result, minLeft[i - 1] - rightSum);
        }
        
        return result;
    }
};