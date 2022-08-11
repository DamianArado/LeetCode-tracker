class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for(int num : nums) minHeap.add(-1 * num);
        for(int i = 1; i < n; i += 2) nums[i] = -1 * minHeap.poll();
        for(int i = 0; i < n; i += 2) nums[i] = -1 * minHeap.poll();
        return nums;
    }
}