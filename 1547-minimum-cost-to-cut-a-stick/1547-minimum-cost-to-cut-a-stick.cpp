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

Approach 2: Using memoization - O(c^3) TC & O(c^2 + c) SC, where c is the size of given cuts array

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

Approach 3: Tabulation based - O(c^2) TC & SC
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        // as the cuts can be made at these 5 locations only for cuts[]: [1, 2, 4, 5, 6]
        // adding 1 extra as when i = c, idx will access i + 1
        vector<vector<int>> dp(c + 2, vector<int> (c + 2, 0));
        
        for(int i = c; i >= 1; --i) {
            for(int j = 1; j <= c; ++j) {
                if(i > j) continue;
                int minTotalCost = 1e9;
                for(int idx = i; idx <= j; ++idx) {
                    int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][idx - 1] + dp[idx + 1][j];
                    minTotalCost = min(minTotalCost, cost);
                }
                dp[i][j] = minTotalCost;
            }
        }
        return dp[1][c];
    }
};