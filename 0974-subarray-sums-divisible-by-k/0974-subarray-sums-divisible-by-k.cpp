class Solution {
/**
Extension of Subarray sum divisible by k
Instead of map we will only count the no. of times we saw the remainder
just in case we get a -ve runningSum, we will increase it by k
*/
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int runningSum = 0, ans = 0;
        vector<int> count(k);
        count[0] = 1;  // an empty array is always divisible by k
        for(int &num : nums) {
            runningSum = (runningSum + num) % k;
            if(runningSum < 0) runningSum += k;
            ans += count[runningSum]++;
        }
        return ans;
    }
};