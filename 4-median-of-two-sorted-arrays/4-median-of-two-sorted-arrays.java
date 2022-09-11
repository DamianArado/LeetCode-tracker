class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length, start = 0;
        
        if(n1 > n2) 
            return findMedianSortedArrays(nums2, nums1);
        
        int end = n1;
        while(start <= end) {
            int cut1 = start + (end - start) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;
            
            int left1 = cut1 != 0 ? nums1[cut1 - 1] : Integer.MIN_VALUE;
            int left2 = cut2 != 0 ? nums2[cut2 - 1] : Integer.MIN_VALUE;
            int right1 = cut1 != n1 ? nums1[cut1] : Integer.MAX_VALUE;
            int right2 = cut2 != n2 ? nums2[cut2] : Integer.MAX_VALUE;
            
            if(left1 <= right2 && left2 <= right1) {
                if((n1 + n2) % 2 == 0) 
                    return (Math.max(left1, left2) + Math.min(right1, right2)) / 2.0;
                else 
                    return Math.max(left1, left2);
            } 
            else if(left1 > right2) end = cut1 - 1;
            else start = cut1 + 1;
        }
        return 0.0;
    }
}