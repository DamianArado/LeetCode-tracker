class Solution {
public:
    // Modifying input
    // int findDuplicate(vector<int>& nums) {
    //     for(int &num : nums) {
    //         int idx = abs(num);
    //         if(nums[idx] < 0) return idx;
    //         nums[idx] = -nums[idx];
    //     }
    //     return -1;
    // }
    int findDuplicate(vector<int>& nums) {
        int n = size(nums);
        if(n < 2) return -1;
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};