class Solution {
public:
    ///////////////////////////////////////////////////////////////////////
    //  Just observe these test cases -                                 ///
    //    n       broken into       product         answer              ///
    //    7       3 + 4             3 * 4            12                 ///
    //    8       3 + 3 + 2         3 * 3 * 2        18                 ///
    //    9       3 + 3 + 3         3 * 3 * 3        27                 ///
    //    10      3 + 3 + 4         3 * 3 * 4        36                 ///
    //    11      3 + 3 + 3 + 2     3 * 3 * 3 * 2    54                 ///
    ///////////////////////////////////////////////////////////////////////
    //  The idea is to utilize as many 3's as possible (~ n % 3)        ///
    //  if n % 3 == 0, ans = 3 * (n % 3)                                ///
    //  if n % 3 == 1, ans = 4 * (n % 3)                                ///
    //  else ans = 2 * (n % 3)                                          ///
    ///////////////////////////////////////////////////////////////////////
    // Time: O(N), Space: O(1)                                          ///
    ///////////////////////////////////////////////////////////////////////
    int integerBreak(int n) {
        // edge cases
        if (n == 2 or n == 3) 
            return n - 1;
        int ans = 1;
        if (n % 3 == 0) {
            for (int i = 0; i < n / 3; ++i)
                ans *= 3;
        } else if (n % 3 == 1) {
            for (int i = 0; i < n / 3 - 1; ++i)
                ans *= 3;
            ans *= 4;
        } else {
             for (int i = 0; i < n / 3; ++i)
                ans *= 3;
            ans *= 2;
        }
        return ans;
    }
};