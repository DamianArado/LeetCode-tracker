/***

class Solution {
public:
    // brute force - O(m + n) time & O(m + n) space which can be optimized to O(1) space using a counter
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0;
        vector<int> nums3;
        while(i < m and j < n) {
            if(nums1[i] < nums2[j]) {
                nums3.emplace_back(nums1[i]);
                i++;
            } else {
                nums3.emplace_back(nums2[j]);
                j++;
            }
        }
        while(i < m) nums3.emplace_back(nums1[i++]);
        while(j < n) nums3.emplace_back(nums2[j++]);
        
        int len = nums3.size();
        double median = 0.0;
        
        if(len % 2 == 1) median = nums3[len / 2];
        else median = (nums3[len / 2 - 1] + nums3[len / 2]) / 2.0;
        
        return median;
    }
};

*/

class Solution {
public:
    // most optimized - O(log (min (n1, n2))) time & O(1) space 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = size(nums1), n2 = size(nums2), start = 0;
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int end = n1;
        // binary search
        while(start <= end) {
            // make 2 cuts - one in nums1 and the other on nums2
            int cut1 = start + (end - start) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;
            // divide the elements in both the arrays into partitions
            int left1 = cut1 != 0 ? nums1[cut1 - 1] : INT_MIN;
            int left2 = cut2 != 0 ? nums2[cut2 - 1] : INT_MIN;
            int right1 = cut1 != n1 ? nums1[cut1] : INT_MAX;
            int right2 = cut2 != n2 ? nums2[cut2] : INT_MAX;
            
            if(left1 <= right2 and left2 <= right1) {
                // even case
                if((n1 + n2) % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                // odd case
                else 
                    return max(left1, left2);
            } else if(left1 > right2)
                end = cut1 - 1;
            else start = cut1 + 1;
        }
        return 0.0;
    }
};