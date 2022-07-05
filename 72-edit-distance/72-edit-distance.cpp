/**

Approach 1: Using recurrence - O(3^(n1 + n2)) TC & O(n1 + n2) SC

class Solution {
private:
    int f(int idx1, int idx2, string &word1, string &word2) {
        // min steps required to convert "" -> word2[0...idx2]   (insertions)
        if(idx1 == -1) return idx2 + 1;
        // min steps required to convert word1[0...idx1] -> ""   (deletions)
        if(idx2 == -1) return idx1 + 1;
        // match - no operations required
        if(word1[idx1] == word2[idx2]) return 0 + f(idx1 - 1, idx2 - 1, word1, word2);
        // not a match - 3 operations possible
        int insert = 1 + f(idx1, idx2 - 1, word1, word2);
        int delet = 1 + f(idx1 - 1, idx2, word1, word2);
        int replace = 1 + f(idx1 - 1, idx2 - 1, word1, word2);
        // min possible operations
        return min(insert, min(delet, replace));
    }
public:
    int minDistance(string word1, string word2) {
        return f(word1.size() - 1, word2.size() - 1, word1, word2);
    }
};

Approach 2: Using memoization - O(n1.n2) TC & O(n1.n2 + (n1 + n2)) SC



*/
class Solution {
private:
    int f(int idx1, int idx2, string &word1, string &word2, vector<vector<int>> &dp) {
        // min steps required to convert "" -> word2[0...idx2]   (insertions)
        if(idx1 == -1) return idx2 + 1;
        // min steps required to convert word1[0...idx1] -> ""   (deletions)
        if(idx2 == -1) return idx1 + 1;
        // if its already precomputed
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        // match - no operations required
        if(word1[idx1] == word2[idx2]) 
            return dp[idx1][idx2] = 0 + f(idx1 - 1, idx2 - 1, word1, word2, dp);
        // not a match - 3 operations possible
        int insert = 1 + f(idx1, idx2 - 1, word1, word2, dp);
        int delet = 1 + f(idx1 - 1, idx2, word1, word2, dp);
        int replace = 1 + f(idx1 - 1, idx2 - 1, word1, word2, dp);
        // min possible operations
        return dp[idx1][idx2] = min(insert, min(delet, replace));
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return f(n1 - 1, n2 - 1, word1, word2, dp);
    }
};