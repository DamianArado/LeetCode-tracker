class Solution {
    public int findJudge(int n, int[][] trust) {
        if(trust.length == 0) return n == 1 ? 1 : -1;
        int[] balance = new int[n + 1];
        for(int[] t : trust) {
            --balance[t[0]];
            ++balance[t[1]];
        }
        for(int i = 0; i <= n; ++i)
            if(balance[i] == n - 1) 
                return i;
        return -1;
    }
}