class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        // the plan is to increase the value in window or
        // increase the window slowly so as to get the max score
        // the least score is when i = k = j
        // start here and increase the window size accordingly
        // if nums[i - 1] < nums[j + 1] do j++
        // else do i--
        int maxScore = nums[k], i = k, j = k, minNum = nums[k], n = size(nums);
        while (i > 0 or j < n - 1) {
            if ((i > 0 ? nums[i - 1] : 0) < (j < n - 1 ? nums[j + 1] : 0))
                minNum = min(minNum, nums[++j]);
            else 
                minNum = min(minNum, nums[--i]);
            maxScore = max(maxScore, minNum * (j - i + 1));
        }
        return maxScore;
    }
};