class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLen = 0;
        unordered_map<int, int> dp;
        for(int &num : nums) {
            dp[num]++;
            if(dp.count(num - 1)) maxLen = max(maxLen, dp[num] + dp[num - 1]);
            if(dp.count(num + 1)) maxLen = max(maxLen, dp[num] + dp[num + 1]);
        }
        return maxLen;
    }
};