class Solution {
public:
    int numArr(vector<int> &nums, int k) {
        int ans = 0, count = 0;
        int i = 0, j = 0, n = nums.size();
        while(j < n) {
            if(nums[j] % 2 == 1) ++count;
            if(count > k) {
                while(i <= j && count > k) {
                    if(nums[i] % 2 == 1) --count;
                    ++i;
                }
            }
            ans += j - i + 1;
            ++j;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numArr(nums, k) - numArr(nums, k - 1);
    }
};