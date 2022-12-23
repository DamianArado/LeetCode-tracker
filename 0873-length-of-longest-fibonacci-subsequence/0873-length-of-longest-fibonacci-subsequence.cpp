class Solution {
public:
    /**
    
    Very good follow up question of Two sum - input array is sorted.
    Approach would be to construct a dp table where we will try to find pairs. 
    arr[l] & arr[r] which can sum up to arr[i].
    Thus, dp[r][i] means the length of longest fibonacci sequence that ends with arr[r] & arr[i].
    such that arr[l] + arr[r] = arr[i].
    Also, dp[r][i] = 1 + dp[l][r] is the state updation.
    
    */
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = size(arr), maxLen = 0;
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i = 2; i < n; ++i) {
            int l = 0, r = i - 1;
            while(l < r) {
                int sum = arr[l] + arr[r];
                if(sum < arr[i]) ++l;
                else if(sum > arr[i]) --r;
                else {
                    dp[r][i] = 1 + dp[l][r];
                    maxLen = max(maxLen, dp[r][i]);
                    ++l, --r;
                }
            }
        }
        return maxLen != 0 ? maxLen + 2 : maxLen;
    }
};