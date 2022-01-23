class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = m - 1, b = n - 1, writeIdx = m + n - 1;
        while(a >= 0 && b >= 0) nums1[writeIdx--] = nums1[a] > nums2[b] ? nums1[a--] : nums2[b--];
        while(b >= 0) nums1[writeIdx--] = nums2[b--];
    }
};