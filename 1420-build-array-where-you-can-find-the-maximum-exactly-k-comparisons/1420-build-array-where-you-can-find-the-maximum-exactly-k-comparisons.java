class Solution {
    public int numOfArrays(int n, int m, int k) {
        Integer[][][] dp = new Integer[n + 1][m + 1][k + 1];
        return dfs(n, m, k, 0, 0, 0, dp);
    }
    // dfs(... i, currMax, currCost) the number of ways to build the valid array `arr[i:]`
    //     keeping in mind that current maximum element is `currMax` and current search cost is `currCost`
    int dfs(int n, int m, int k, int i, int currMax, int currCost, Integer[][][] dp) {
        if (i == n) {
            if (k == currCost) return 1; // valid if the value search cost is equal to k
            return 0;
        }
        if (dp[i][currMax][currCost] != null) return dp[i][currMax][currCost];
        int ans = 0;
        for (int num = 1; num <= m; num++) {
            int newCost = currCost;
            int newMax = currMax;
            if (num > currMax) {
                newCost++;
                newMax = num;
            }
            if (newCost > k) break;
            ans += dfs(n, m, k, i + 1, newMax, newCost, dp);
            ans %= 1_000_000_007;
        }
        return dp[i][currMax][currCost] = ans;
    }
}