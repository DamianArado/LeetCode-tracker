/**

Recurrence: 

index1 and index2 both start at str1.length - 1 and str2.length - 1 respectively

f(index1, index2):
    if index1 == -1 or index2 == -1 :
        return 0
    if str1[index1] == str2[index2] : 
        return 1 + f(index1 - 1, index2 - 1)
    return max(f(index1 - 1, index2), f(index1, index2 - 1))
    
TC: O(2^n1 * 2^n2), SC: (n1 + n2)

*/
class Solution {
private:
    int f(int index1, int index2, string &text1, string &text2, vector<vector<int>> &dp) {
        // base case
        if(index1 == -1 or index2 == -1) return 0;
        // check if its already computed
        if(dp[index1][index2] != -1)
            return dp[index1][index2];
        // matched
        if(text1[index1] == text2[index2])
            return dp[index1][index2] = 1 + f(index1 - 1, index2 - 1, text1, text2, dp);
        // not matched
        return dp[index1][index2] = max(f(index1 - 1, index2, text1, text2, dp), 
                                        f(index1, index2 - 1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return f(n1 - 1, n2 - 1, text1, text2, dp);
    }
};