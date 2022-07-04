class Solution {
public:
    // O(mn) TC & SC
    string shortestCommonSupersequence(string str1, string str2) {
        // we will be using LCS to find SCS
        int m = str1.size(), n = str2.size();
        // 1-based indexing
        vector<vector<int>> lcs(m + 1, vector<int> (n + 1, 0));
        // build the LCS table bottom up using DP
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                // match
                if(str1[i - 1] == str2[j - 1])
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                // not a match
                else 
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        // now iterate over the LCS table from the last cell and create a reversed SCS
        string scs = "";
        int row = m, col = n;
        while(row > 0 and col > 0) {
            // if both chars match, we take them only once
            if(str1[row - 1] == str2[col - 1]) {
                scs += str1[row - 1];
                row--; col--;
            } else if(lcs[row - 1][col] > lcs[row][col - 1]) {
                // current value in the LCS table came from the upper row
                // so we take the value from row in the current cell and move up and reduce row
                scs += str1[row - 1];
                row--;
            } else {
                // current value in the LCS table came from the left column
                // so we take the value from column in the current cell and move left and reduce column
                scs += str2[col - 1];
                col--;
            }
        }
        // adding the remaining characters: either in row or column, some characters may be left to be added
        while(row > 0) {
            scs += str1[row - 1];
            row--;
        }
        while(col > 0) {
            scs += str2[col - 1];
            col--;
        }
        // reverse to get the required SCS
        reverse(scs.begin(), scs.end());
        return scs;
    }
};