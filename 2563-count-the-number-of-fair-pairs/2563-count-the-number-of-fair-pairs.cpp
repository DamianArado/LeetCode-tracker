class Solution {
private:
    long long countLessThanVal(vector<int> &nums, int value) {
        long long ans = 0;
        for(int i = 0, j = size(nums) - 1; i < j; ++i) {
            while(i < j and nums[i] + nums[j] >= value) --j;
            // adding these pairs
            ans += (j - i);
        }
        return ans;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        // Count number of pairs having sum less than upper + 1 : sum1
        // Count number of pairs having sum less than lower : sum2
        // Required value = sum1 - sum2
        return countLessThanVal(nums, upper + 1) - countLessThanVal(nums, lower);
    }
};