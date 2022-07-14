/**

Approach 1: Basic recurrence - O(exponential) TC & O(n) SC

class Solution {
private:
    int f(int i, int j, vector<int> &cuts) {
        if(i > j) return 0;
        int minCost = 1e9;
        for(int idx = i; idx <= j; ++idx) {
            int cost = cuts[j + 1] - cuts[i - 1] + f(i, idx - 1, cuts) + f(idx + 1, j, cuts);
            minCost = min(minCost, cost);
        }
        return minCost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return f(1, c, cuts);
    }
};

Approach 2: Using memoization - O()
*/

class Solution {
private:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int minCost = 1e9;
        for(int idx = i; idx <= j; ++idx) {
            int cost = cuts[j + 1] - cuts[i - 1] + f(i, idx - 1, cuts, dp) + f(idx + 1, j, cuts, dp);
            minCost = min(minCost, cost);
        }
        return dp[i][j] = minCost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        // as the cuts can be made at these 5 locations only for cuts[]: [1, 2, 4, 5, 6]
        vector<vector<int>> dp(c + 1, vector<int> (c + 1, -1));
        return f(1, c, cuts, dp);
    }
};