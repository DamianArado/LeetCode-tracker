class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = size(nums), ans = 0, i = 0, j = 1;
        sort(begin(nums), end(nums));
        while(j < n) {
            if(nums[i] < nums[j]) {
                ++ans;
                ++i, ++j;
            } else ++j;
        }
        return ans;
    }
};