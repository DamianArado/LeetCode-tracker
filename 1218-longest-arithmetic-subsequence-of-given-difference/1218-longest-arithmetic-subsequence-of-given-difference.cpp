class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;
        for(int &i : arr) {
            if(dp.count(i - difference))
                dp[i] = 1 + dp[i - difference];
            else dp[i] = 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};