class KthLargest {
    private static int k;
    PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    
    public KthLargest(int k, int[] nums) {
        this.k = k;
        for(int num : nums) {
            minHeap.add(num);
            if(minHeap.size() > k) minHeap.poll();
        }
    }
    
    public int add(int val) {
        minHeap.add(val);
        while(minHeap.size() > k) minHeap.poll();
        return minHeap.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */