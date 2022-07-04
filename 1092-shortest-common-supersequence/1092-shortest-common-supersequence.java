class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int m = str1.length(), n = str2.length();
        int[][] lcs = new int[m + 1][n + 1];
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(str1.charAt(i - 1) == str2.charAt(j - 1))
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                else 
                    lcs[i][j] = Math.max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        int row = m, col = n;
        String scs = "";
        while(row > 0 && col > 0) {
            if(str1.charAt(row - 1) == str2.charAt(col - 1)) {
                scs += str1.charAt(row - 1);
                row--; col--;
            } else if(lcs[row - 1][col] > lcs[row][col - 1]) {
                scs += str1.charAt(row - 1);
                row--;
            } else {
                scs += str2.charAt(col - 1);
                col--;
            }
        }
        while(row > 0) {
            scs += str1.charAt(row - 1);
            row--;
        }
        while(col > 0) {
            scs += str2.charAt(col - 1);
            col--;
        }
        
        String ans = new StringBuilder(scs).reverse().toString();
        return ans;
    }
}