class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // you have to do the binary search on the smaller array
        int n1 = size(nums1), n2 = size(nums2);
        if (n1 > n2) 
            return findMedianSortedArrays(nums2, nums1);
        int left = 0, right = n1;
        while (left <= right) {
            // cut1: to cut nums1 and cut2: to cut nums2
            int cut1 = left + (right - left) / 2, cut2 = (n1 + n2 + 1) / 2 - cut1;
            // try placing these cuts in the right positions
            // left1 and left2 largest element on the left partitions
            // right1 and right2 smallest element on the right partitions
            int left1 = cut1 ? nums1[cut1 - 1] : INT_MIN,
                left2 = cut2 ? nums2[cut2 - 1] : INT_MIN,
                right1 = cut1 != n1 ? nums1[cut1] : INT_MAX,
                right2 = cut2 != n2 ? nums2[cut2] : INT_MAX;
            // if these are exactly where we want them to be!
            if (left1 <= right2 and left2 <= right1)
                // even number of total elements
                if ((n1 + n2) % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else 
                    return max(left1, left2);
            // shift the partition in nums1 towards left
            else if (left1 > right2)
                right = cut1 - 1;
            else
                left = cut1 + 1;
        }
        return 0.0;
    }
};