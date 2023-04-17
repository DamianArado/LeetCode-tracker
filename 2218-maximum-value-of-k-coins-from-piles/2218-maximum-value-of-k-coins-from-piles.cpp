class Solution {
private:
    int f(int idx, vector<vector<int>> &piles, int n, int k, vector<vector<int>> &dp) {
        if(idx == n) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        int currentVal = 0, maxVal = 0;
        // not take
        maxVal = max(maxVal, f(idx + 1, piles, n, k, dp));
        // take from top of piles: min 1 and max k 
        for(int i = 0; i < size(piles[idx]); ++i) {
            currentVal += piles[idx][i];
            if(k - (i + 1) >= 0)
                maxVal = max(maxVal, currentVal + f(idx + 1, piles, n, k - (i + 1), dp));
        }
        return dp[idx][k] = maxVal;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = size(piles);
        vector<vector<int>> dp(n, vector<int> (k + 1, -1));
        return f(0, piles, n, k, dp);
    }
};