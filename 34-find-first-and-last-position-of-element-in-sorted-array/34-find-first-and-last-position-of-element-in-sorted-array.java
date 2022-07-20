class Solution {
    private static int findUpperBound(int[] nums, int target) {
        int start = 0, end = nums.length - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] >= target)
                end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
    private static int findLowerBound(int[] nums, int target) {
        int start = 0, end = nums.length - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] <= target)
                start = mid + 1;
            else end = mid - 1;
        }
        return start;
    }
    public int[] searchRange(int[] nums, int target) {
        int startIdx = findUpperBound(nums, target);
        int endIdx = findLowerBound(nums, target);
        int[] ans = new int[2];
        if(startIdx == endIdx) {
            ans[0] = -1;
            ans[1] = -1;
        }
        else {
            ans[0] = startIdx;
            ans[1] = endIdx - 1;
        }
        return ans;
    }
}