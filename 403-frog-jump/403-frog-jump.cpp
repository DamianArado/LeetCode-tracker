/*  Explanation:

                +----+    +----+        +----+     +----+       
stone:          | S1 |    | S2 |        | S3 |     | S4 | 
            ____|____|____|____|________|____|_____|____|____________
           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
position:          0         1             3          5                     

jump size:         1      [0,1,2]       [1,2,3]     [1,2,3]




*/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // dp[i][j] signifies whether you were able to reach stones[i] with a jump of size j
        vector<vector<bool>> dp(n, vector<bool> (n + 1, false));
        // since we can always reach the 1st stone with a jumpSize = 1
        dp[0][1] = true;
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                // the size of the jump made by the frog
                int jumpSize = stones[i] - stones[j];
                // if we can't jump till stones[j] with jumpSize, skip this j
                if(jumpSize >= n or !dp[j][jumpSize]) continue;
                // if we did took a jump previously to stones[j]
                // and if we have a valid jumpSize: 0 <= jumpSize - 1 & jumpSize + 1 < n
                // we can jump till stones[i] with jumpSize
                if(jumpSize - 1 >= 0) 
                    dp[i][jumpSize - 1] = true;
                if(jumpSize + 1 < n)
                    dp[i][jumpSize + 1] = true;
                dp[i][jumpSize] = true;
                // if we reached the end, return true
                if(i == n - 1) return true;
            }
        }
        // we couldn't reach till the part where it checks i == n - 1
        return false;
    }
};