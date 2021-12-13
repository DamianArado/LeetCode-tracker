class Solution {
public:
    int checkRecord(int n) {
        int mod = 1e9+7;
        int dp[n + 1][3];
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[1][2] = 0;
        
        for(int i = 2; i <= n; i++) {
            dp[i][0] = (0LL + dp[i-1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
            dp[i][1] = (0LL + dp[i - 1][0]) % mod;
            dp[i][2] = (0LL + dp[i - 2][0]) % mod;
        }

        long long ans = 0LL + dp[n][0] + dp[n][1] + dp[n][2];
        
        for(int i = 0; i < n; i++) {
            int l = (0LL + dp[i][0] + dp[i][1] + dp[i][2]) % mod;
            int r = (0LL + dp[n - 1 - i][0]+ dp[n - 1 - i][1]+dp[n - 1 - i][2]) % mod;
            ans = (ans + l*1LL*r) % mod;
        }
        
        return ans;
    }
};