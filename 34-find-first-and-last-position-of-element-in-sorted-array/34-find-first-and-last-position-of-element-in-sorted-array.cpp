class Solution {
private:
    int findLowerBound(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] <= target)
                start = mid + 1;
            else end = mid - 1;
        }
        return start;
    }
    int findUpperBound(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] >= target)
                end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startIdx = findUpperBound(nums, target);
        int endIdx = findLowerBound(nums, target);
        if(startIdx == endIdx) return {-1, -1};
        else return {startIdx, endIdx - 1};
    }
};