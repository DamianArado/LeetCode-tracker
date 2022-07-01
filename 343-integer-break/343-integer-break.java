class Solution {
    public int integerBreak(int n) {
        // edge cases
        if(n == 2 | n == 3) return n - 1;
        int ans = 1;
        if(n % 3 == 0) {
            for(int i = 0; i < n / 3; ++i)
                ans *= 3;
        } else if(n % 3 == 1) {
            for(int i = 0; i < n / 3 - 1; ++i)
                ans *= 3;
            ans *= 4;
        } else {
             for(int i = 0; i < n / 3; ++i)
                ans *= 3;
            ans *= 2;
        }
        return ans;
    }
}