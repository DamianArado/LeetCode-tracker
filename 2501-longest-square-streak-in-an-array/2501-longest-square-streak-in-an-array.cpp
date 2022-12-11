class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Solving this DP problem in 2 steps:
        // Step 1: sort the nums array
        // Step 2: for each element in nums, check if it is a perfect square
        // if it is, increase the count of elements inside our current streak
        // dp[num] = 1 + dp[squareRoot]
        // else just mark it as one so that it can be used later as a squareRoot for
        // another larger number
        sort(begin(nums), end(nums));
        unordered_map<int, int> dp;
        int ans = 0;
        for(int &num : nums) {
            int sqr = sqrt(num);
            if(sqr * sqr == num)
                dp[num] = 1 + dp[sqr];
            else
                dp[num] = 1;
            ans = max(ans, dp[num]);
        }
        return ans > 1 ? ans : -1;
    }
};