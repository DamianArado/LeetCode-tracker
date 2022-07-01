/**
*  Link: https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

Approach 1: Memoization - O(N^2) TC and O(N^2 + N) SC

int f(int index, int rodSize, vector<int> &price, vector<vector<int>> &dp) {
    if(index == 0)
        return (price[0] * rodSize);
    if(dp[index][rodSize] != -1) return dp[index][rodSize];
    int notTake = f(index - 1, rodSize, price, dp);
    int take = INT_MIN;
    int rodPiece = index + 1;
    if(rodPiece <= rodSize)
        take = price[index] + f(index, rodSize - rodPiece, price, dp);
    return dp[index][rodSize] = max(take, notTake);
}
int cutRod(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int> (n + 1, -1));
    return f(n - 1, n, price, dp);
}

Approach 2: Tabulation - O(N^2) TC & SC

int cutRod(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int> (n + 1, 0));
    // base case 
    for(int j = 1; j <= n; ++j)
        dp[0][j] = j * price[0];
    for(int index = 1; index < n; ++index) {
        for(int rod = 1; rod <= n; ++rod) {
            int taken = INT_MIN, piece = index + 1;
            int notTaken = dp[index - 1][rod];
            if(piece <= rod)
                taken = price[index] + dp[index][rod - piece];
            dp[index][rod] = max(taken, notTaken);
        }
    }
    return dp[n - 1][n];
}

Space optimization

TC: O(N^2), SC: O(N)

*
*/


int cutRod(vector<int> &price, int n) {
    vector<int> dp(n + 1, 0);
    // base case 
    for(int j = 1; j <= n; ++j)
        dp[j] = j * price[0];
    for(int index = 1; index < n; ++index) {
        vector<int> current(n + 1, 0);
        for(int rod = 1; rod <= n; ++rod) {
            int taken = INT_MIN, piece = index + 1;
            int notTaken = dp[rod];
            if(piece <= rod)
                taken = price[index] + current[rod - piece];
            current[rod] = max(taken, notTaken);
        }
        dp = current;
    }
    return dp[n];
}
