class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[size(days) - 1];
        // dp[i] will store the min dollars needed to travel till day i
        vector<int> dp(lastDay + 1);
        vector<bool> isTravelDay(lastDay + 1);
        for(const int &day : days)
            isTravelDay[day] = true;
        for(int i = 1; i <= lastDay; ++i) {
            // if its not a travel day no need for any calculation
            if(!isTravelDay[i])
                dp[i] = dp[i - 1];
             else {
                 dp[i] = costs[0] + dp[i - 1];  // 1-day pass
                 dp[i] = min(dp[i], costs[1] + dp[max(i - 7, 0)]);  // 7-day pass
                 dp[i] = min(dp[i], costs[2] + dp[max(i - 30, 0)]);  // 30-day pass
             }
        }
        return dp[lastDay];
    }
};