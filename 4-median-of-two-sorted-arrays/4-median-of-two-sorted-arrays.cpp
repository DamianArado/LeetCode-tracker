class Solution {
public:
    // brute force - O(m + n) time & O(m + n) space
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