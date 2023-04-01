function search(nums: number[], target: number): number {
    let start: number = 0;
    let end: number = nums.length - 1;
    while(start <= end) {
        let mid: number = start + Math.floor((end - start) / 2);
        if (target === nums[mid]) return mid;
        else if (nums[mid] <= target) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
};