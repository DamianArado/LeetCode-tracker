class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        int cumSum = 0, ans = -1;
        for(int i = 0; i < size(nums); ++i) {
            cumSum += nums[i];
            if(cumSum - nums[i] == sum - cumSum) { ans = i; break; }
        }
        return ans;
    }
};