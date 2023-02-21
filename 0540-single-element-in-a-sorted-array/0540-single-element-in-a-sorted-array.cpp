class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // for ex. [1,1,3,3,4,4,6,6,7,9,9]
        // we can see for each pair at even idx we have the 1st occurrence and at odd idx the 2nd occurrence
        // for each mid we will see if we have the pattern going as it is and as soon as we don't see that
        // we will stop going to the right half and search in the left half
        if(size(nums) == 1) return nums[0];
        int start = 0, end = size(nums) - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if((mid % 2 == 0 and nums[mid] == nums[mid + 1]) 
               or (mid % 2 == 1 and nums[mid] == nums[mid - 1])) start = mid + 1;
            else end = mid - 1;
        }
        return nums[start];
    }
};