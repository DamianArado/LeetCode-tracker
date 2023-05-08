function search(nums: number[], target: number): number {
    let start: number = 0;
    let end: number = nums.length - 1;
    while(start <= end) {
        let mid: number = start + Math.floor((end - start) / 2);
        if(nums[mid] == target) return mid;
        // check if 1st half is unsorted; search in sorted half
        if(nums[mid] > nums[end]) {
            if(target >= nums[start] && target < nums[mid]) end = mid - 1;
            else start = mid + 1;
        }
        // check if 2nd half is unsorted; search in sorted half
        else if(nums[mid] < nums[start]) {
            if(target > nums[mid] && target <= nums[end]) start = mid + 1;
            else end = mid - 1;
        }
        // else seach in the whole sorted region using normal binary search
        else {
            if(nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
    }
    return -1;
};