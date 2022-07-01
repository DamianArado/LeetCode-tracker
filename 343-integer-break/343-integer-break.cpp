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
    //  else ans = 4 * (n % 3)                                          ///
    ///////////////////////////////////////////////////////////////////////
    // Time: O(N), Space: O(1)                                          ///
    ///////////////////////////////////////////////////////////////////////
    long int integerBreak(int n) {
        // edge cases
        switch(n) {
            case 2:
                return 1;
                break;
            case 3:
                return 2;
                break;
        }
        
        long int ans = 1;
        
        if(n % 3 == 0) {
            int times = n / 3;
            for(int i = 0; i < times; ++i)
                ans *= 3;
            return ans;
        } 
        else if(n % 3 == 2) {
            int times = n / 3;
            for(int i = 0; i < times; ++i)
                ans *= 3;
            return ans * 2;
        } 
        else {
            int times = n / 3 - 1;
            for(int i = 0; i < times; ++i)
                ans *= 3;
            return ans * 4; 
        }
    }
};