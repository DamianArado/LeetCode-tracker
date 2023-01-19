class Solution {
public:
    /**
    
    Brute force is to do a O(n^2) for each subarray. 
    Better is to use Prefix sum + Remainder trick for this problem for O(n) time.
    
    We'll continously do the prefix sum and take remainder out of them. 
    Then, using a map, we will check whether we had seen this remainder 
    earlier or not. If yes, then if
    i - index where this remainder was previously seen
    j - index where the remainder is next seen
    
    Hence, in the range: [i + 1, j] we would have added something that is a multiple of k
    since at each index we are doing mod k.
    
    For e.x., arr = [23, 2, 4, 6, 7] and k = 6
      Running sum = [23, 25, 29, 35, 42]
          Sum % k = [5, 1, 5, 5, 0]
      We can see that we have found ranges: [1, 2], [1, 3] and [0, 4] where we 
      had our required subarray.
    */
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = size(nums);
        if(n < 2) return false;
        
        unordered_map<int, int> mp;  // remainder : index
        mp[0] = -1;
        int runningSum = 0;
        
        for(int i = 0; i < n; ++i) {
            runningSum += nums[i];
            runningSum %= k;
            if(mp.count(runningSum)) {
                if(i - mp[runningSum] > 1)
                    return true;
            }
            else mp[runningSum] = i;
        }
        return false;
    }
};