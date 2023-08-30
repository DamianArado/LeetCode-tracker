class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = size(nums), last = nums[n - 1];
        long long replacements = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (last < nums[i]) {
                int parts = nums[i] / last;
                if (nums[i] % last != 0) 
                    ++parts;
                replacements += (parts - 1);
                last = nums[i] / parts;
            } else 
                last = nums[i];
        }
        return replacements;
    }
};