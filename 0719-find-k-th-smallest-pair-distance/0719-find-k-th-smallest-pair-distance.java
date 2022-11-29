class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int minDist = 0, maxDist = nums[n - 1] - nums[0];
        while(minDist <= maxDist) {
            int midDist = minDist + (maxDist - minDist) / 2;
            int left = 0, right = 0, count = 0;
            while(right < n) {
                if(nums[right] - nums[left] > midDist) ++left;
                else {
                    count += (right - left);
                    ++right;
                }
            }
            if(count >= k) maxDist = midDist - 1;
            else minDist = midDist + 1;
        }
        return minDist;
    }
}