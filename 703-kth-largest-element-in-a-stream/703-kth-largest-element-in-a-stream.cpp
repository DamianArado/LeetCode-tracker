class KthLargest {
private:
    int K;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int num : nums) {
            minHeap.push(num);
            if(minHeap.size() > k) 
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        while(minHeap.size() > K) 
            minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */