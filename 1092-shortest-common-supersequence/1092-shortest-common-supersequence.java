class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int n1 = str1.length(), n2 = str2.length();
        // Step1: a DP table constructed using LCS
        int[][] dp = new int[n1 + 1][n2 + 1];
        for(int i1 = 1; i1 <= n1; ++i1) {
            for(int i2 = 1; i2 <= n2; ++i2) {
                if(str1.charAt(i1 - 1) == str2.charAt(i2 - 1))
                    dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                else
                    dp[i1][i2] = Math.max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
            }
        }
        
        // Step2: using this table construct the SCS
        int row = n1, col = n2;
        String scs = "";
        while(row > 0 && col > 0) {
            if(str1.charAt(row - 1) == str2.charAt(col - 1)) {
                scs += str1.charAt(row - 1);
                --row;
                --col;
            } else if(dp[row][col - 1] > dp[row - 1][col]) {
                scs += str2.charAt(col - 1);
                --col;
            } else {
                scs += str1.charAt(row - 1);
                --row;
            }
        }
        while(row > 0) {
            scs += str1.charAt(row - 1);
            --row;
        }
        while(col > 0) {
            scs += str2.charAt(col - 1);
            --col;
        }
        return new StringBuilder(scs).reverse().toString();
    }
}