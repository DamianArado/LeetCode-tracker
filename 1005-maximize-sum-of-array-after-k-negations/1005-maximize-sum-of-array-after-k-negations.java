class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int maxSum = 0;
        for(int num : nums)
            minHeap.add(num);
        while(k-- > 0) {
            int num = minHeap.poll();
            minHeap.add(-1 * num);
        }
        while(!minHeap.isEmpty())
            maxSum += minHeap.poll();
        return maxSum;
    }
}