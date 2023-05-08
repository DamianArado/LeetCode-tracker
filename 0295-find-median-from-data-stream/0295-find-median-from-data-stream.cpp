class MedianFinder {
private:
    // SC - O(N)
    // max heap to store the min numbers (having lower values)
    priority_queue<int> maxHeap;
    // min heap to store the max numbers (having higher values)
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {}
    
    // TC - O(logn)
    void addNum(int num) {
        // Firstly, we add this number inside the maxHeap and then we try to balance the sizes of both minHeap and maxHeap
        maxHeap.emplace(num);
        // then we push the max among the min numbers inside the min heap
        minHeap.emplace(maxHeap.top());
        maxHeap.pop();
        // if min heap has more numbers we push the min among the max numbers inside the max heap
        // this makes sure we are pushing min numbers inside max heap and max numbers inside min heap
        if(size(minHeap) > size(maxHeap)) {
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }
    }
    // TC - O(1)
    double findMedian() {
        // if maxHeap has more elements, the max one is the answer since its balanced
        if(size(maxHeap) > size(minHeap))
            return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};