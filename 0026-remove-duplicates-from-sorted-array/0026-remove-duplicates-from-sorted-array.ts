function removeDuplicates(nums: number[]): number {
    let ans: number = 1;
    for(let i = 1; i < nums.length; ++i)
        if(nums[i] != nums[i - 1])  {  
            nums[ans] = nums[i]; 
            ++ans; 
        }
    return ans;
};