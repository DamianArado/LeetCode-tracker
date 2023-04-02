function findDuplicate(nums: number[]): number {
    let slow: number = nums[0];
    let fast: number = nums[nums[0]];
    while(slow !== fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = 0;
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
};