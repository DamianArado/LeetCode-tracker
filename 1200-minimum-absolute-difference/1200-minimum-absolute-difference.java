class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] nums) {
        int n = nums.length, minDiff = Integer.MAX_VALUE;
        
        List<List<Integer>> minDiffPairs = new ArrayList<>();
        Arrays.sort(nums);
        
        for(int i = 1; i < n; ++i) 
            minDiff = Math.min(minDiff, nums[i] - nums[i - 1]);
        
        for(int i = 1; i < n; ++i)
            if(nums[i] - nums[i - 1] == minDiff)
                minDiffPairs.add(Arrays.asList(nums[i - 1], nums[i]));
        
        return minDiffPairs;
    }
}