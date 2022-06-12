class MedianFinder {
    
    private PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    private PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

    public MedianFinder() {}
    
    public void addNum(int num) {
        maxHeap.offer(num);
        minHeap.offer(maxHeap.poll());
        if(minHeap.size() > maxHeap.size())
            maxHeap.offer(minHeap.poll());
    }
    
    public double findMedian() {
        if(maxHeap.size() > minHeap.size())
            return maxHeap.peek();
        return (maxHeap.peek() + minHeap.peek()) / 2.00000;
    }
}