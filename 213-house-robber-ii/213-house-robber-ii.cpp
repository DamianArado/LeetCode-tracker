class Solution {
private:
    int maxRob(vector<int> &nums, int l, int r) {
        int prev2 = 0, prev = nums[l];
        for(int i = l + 1; i < r; ++i) {
            int pick = nums[i] + prev2;
            int dontPick = prev;
            int currentMax = max(pick, dontPick);
            prev2 = prev;
            prev = currentMax;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        // O(n) tc & O(1) sc 
        // just took into account that first and last can't exist together
        int n = nums.size();
        if(n == 1) return nums[0];
        // ignore the last element or the first element
        return max(maxRob(nums, 0, n - 1), maxRob(nums, 1, n));
    }
};