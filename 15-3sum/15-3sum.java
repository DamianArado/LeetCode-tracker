class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> triplets = new ArrayList<>();
        Arrays.sort(nums);
        for(int i = 0; i < n - 2; ++i) {
            if(nums[i] > 0) return triplets;
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int j = i + 1, k = n - 1, reqSum = -nums[i];
                while(j < k) {
                    if(nums[j] + nums[k] == reqSum) {
                        triplets.add(Arrays.asList(nums[i], nums[j], nums[k]));
                        while(j < k && nums[j] == nums[j + 1]) ++j;
                        while(j < k && nums[k] == nums[k - 1]) --k;
                        ++j;
                        --k;
                    }
                    else if(nums[j] + nums[k] > reqSum) --k;
                    else ++j;
                }
            }
        }
        return triplets;
    }
}