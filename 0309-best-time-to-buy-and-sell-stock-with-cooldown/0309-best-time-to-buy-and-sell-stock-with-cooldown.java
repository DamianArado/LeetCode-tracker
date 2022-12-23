// class Solution {
//     public int maxProfit(int[] prices) {
//         int n = prices.length;
//         int dp[][] = new int[n + 2][2];
//         for(int i = n - 1; i >= 0; --i) {
//             for(int j = 1; j >= 0; --j) {
//                 int profit = 0;
//                 if(j == 1) profit = Math.max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
//                 else profit = Math.max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
//                 dp[i][j] = profit;
//             }
//         }
//         return dp[0][1];
//     }
// }

//Space Optimized ;D
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] next2 = new int[2], next1 = new int[2];
        for(int i = n - 1; i >= 0; --i) {
            int[] curr = new int[2];
            for(int j = 1; j >= 0; --j) {
                int profit = 0;
                if(j == 1) profit = Math.max(-prices[i] + next1[0], next1[1]);
                else profit = Math.max(prices[i] + next2[1], next1[0]);
                curr[j] = profit;
            }
            next2 = next1;
            next1 = curr;
        }
        return next1[1];
    }
}