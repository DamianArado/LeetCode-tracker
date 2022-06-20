class Solution {
public:
    int rob(vector<int>& nums) {
        // O(n) tc & O(1) sc 
        // just took into account that first and last can't exist together
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev2 = 0, prev = nums[0], sum1;
        // ignore the last element
        for(int i = 1; i < n - 1; ++i) {
            int pick = nums[i] + prev2;
            int dontPick = prev;
            int currentMax = max(pick, dontPick);
            prev2 = prev;
            prev = currentMax;
        }
        // ignore the first element
        sum1 = prev, prev2 = 0, prev = nums[1];
        for(int i = 2; i < n; ++i) {
            int pick = nums[i] + prev2;
            int dontPick = prev;
            int currentMax = max(pick, dontPick);
            prev2 = prev;
            prev = currentMax;
        }
        return max(sum1, prev);
    }
};