class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = size(scores);
        if(n == 1) return scores[0];
        vector<vector<int>> players(n, vector<int> (2));
        for(int i = 0; i < n; ++i)
            players[i][0] = ages[i], players[i][1] = scores[i];
        sort(begin(players), end(players), greater<>());
        // dp[i] is the max score obtained till index i, including the index i
        int ans = 0;
        vector<int> dp(n);
        for(int i = 0; i < n; ++i) {
            int score = players[i][1];
            dp[i] = score;
            for(int j = 0; j < i; ++j)
                // each age is greater, just make sure score is not strictly increasing
                if(players[j][1] >= score)
                    dp[i] = max(dp[i], dp[j] + score);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};