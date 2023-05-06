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
        if(size(nums) < 2) return nums[0];
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};