class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = size(nums);
        if (n == 1) return true;
        if (nums[0] <= nums[n - 1]) {
            for (int i = 1; i < n; ++i)
                if (nums[i - 1] > nums[i])
                    return false;
            return true;
        }
        for (int i = 1; i < n; ++i) 
            if (nums[i - 1] < nums[i])
                return false;
        return true;
    }
};