class Solution {
    public int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int R = Math.min(m - 1, n - 1);
        double result = 1;
        for(int i = 1; i <= R; ++i)
            result = result * (N - R + i) / i;
        return (int)result;
    }
}