class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        // in order to make nums1 equal to nums2, we can increase and decrease an index i and j
        // respectively by k, that means the increase should be equal to decrease in order 
        // for nums1 to be equal to nums2 and also the difference in each indices the difference
        // should be divisible by k otherwise it would not be possible to make an element at that 
        // index equal to another 
        if(k == 0)
            return nums1 == nums2 ? 0 : -1;
        long long posDiff = 0, negDiff = 0;
        for(int i = 0; i < size(nums1); ++i) {
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
        long long ans = -1;
        if(posDiff == negDiff) ans = posDiff / k;
        return ans;
    }
};