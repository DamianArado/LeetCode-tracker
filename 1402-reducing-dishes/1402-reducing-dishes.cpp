class Solution {
private:
    // sollveeddd   a a   hardd questionn by myselffff      yayyyyyyyyyyyyyyyyy!
    int f(int idx, int time, vector<int> &satisfaction, vector<vector<int>> &dp) {
        if(idx == size(satisfaction)) return 0;
        if(dp[idx][time] != -1) return dp[idx][time];
        int take = satisfaction[idx] * time + f(idx + 1, time + 1, satisfaction, dp);
        int notTake = f(idx + 1, time, satisfaction, dp);
        return dp[idx][time] = max(take, notTake);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = size(satisfaction);
        sort(begin(satisfaction), end(satisfaction));
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return f(0, 1, satisfaction, dp);
    }
};