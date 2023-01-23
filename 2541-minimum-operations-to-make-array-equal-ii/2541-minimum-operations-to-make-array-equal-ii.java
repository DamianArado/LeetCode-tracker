class Solution {
    public long minOperations(int[] nums1, int[] nums2, int k) {
        if(k == 0)
            return Arrays.equals(nums1, nums2) ? 0 : -1;
        long posDiff = 0, negDiff = 0;
        for(int i = 0; i < nums1.length; ++i) {
            if(nums1[i] > nums2[i]) {
                if((nums1[i] - nums2[i]) % k == 0)
                    posDiff += (nums1[i] - nums2[i]);
                else return -1;
            } else {
                if((nums2[i] - nums1[i]) % k == 0)
                    negDiff += (nums2[i] - nums1[i]);
                else return -1;
            }
        }
        long ans = -1;
        if(posDiff == negDiff) ans = posDiff / k;
        return ans;
    }
}