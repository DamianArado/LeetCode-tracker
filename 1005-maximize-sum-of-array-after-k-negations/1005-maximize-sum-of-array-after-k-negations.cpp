class Solution {
public:
    // tc - O(nlogn), sc - O(n)
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int maxSum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num : nums) 
            minHeap.push(num);
        // We either take out -ves and make them +ves or we'll negate the lowest +ves possible
        while(k--) {
            int num = minHeap.top();
            minHeap.pop();
            minHeap.push(-1 * num);
        }
        while(!minHeap.empty()) {
            maxSum += minHeap.top();
            minHeap.pop();
        }
        return maxSum;
    }
};