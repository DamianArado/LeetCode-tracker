class Solution {
    public int longestConsecutive(int[] nums) {
        int ans = 0;
        HashSet<Integer> set = new HashSet<>();
        for(int num : nums) set.add(num);
        for(int num : nums) {
            if(set.contains(num - 1)) continue;
            int current = 0;
            while(set.contains(num + current)) ++current;
            ans = Math.max(ans, current);
        }
        return ans;
    }
}