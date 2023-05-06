/**
 Do not return anything, modify nums in-place instead.
 */
function nextPermutation(nums: number[]): void {
    let n: number = nums.length;
    let i: number = n - 1;
    while(i > 0 && nums[i - 1] >= nums[i]) --i;
    if(i == 0)
        nums.reverse();
    else {
        let pivot: number = i - 1;
        let largestGreater: number = n - 1;
        while(largestGreater > i && nums[largestGreater] <= nums[pivot]) --largestGreater;
        [nums[pivot], nums[largestGreater]] = [nums[largestGreater], nums[pivot]];
        let nums2: number[] = nums.slice(i);
        nums2.reverse();
        for(let j = i; j < n; ++j)
            nums[j] = nums2[j - i];
    }
};