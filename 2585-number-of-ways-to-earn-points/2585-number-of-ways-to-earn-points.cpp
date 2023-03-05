class Solution { 
private:
    const int MOD = 1e9 + 7;
    int solve(vector<vector<int>>& types, int i, int marks, int target, vector<vector<int>> &dp) { 
        if(marks > target) 
            return 0; 
        if(marks == target) 
            return 1; 
        if(i == size(types)) 
            return 0; 
        if(dp[i][marks] != -1) 
            return dp[i][marks]; 
        int ans = 0; 
        for(int j = 0; j <= types[i][0]; ++j) { 
            ans += solve(types, i + 1, marks + j * types[i][1], target, dp); 
            ans %= MOD; 
        } 
        return dp[i][marks] = ans; 
    }
public:  
    int waysToReachTarget(int target, vector<vector<int>>& types) { 
        vector<vector<int>> dp(size(types), vector<int>(target + 1, -1)); 
        return solve(types, 0, 0, target, dp); 
    } 
};