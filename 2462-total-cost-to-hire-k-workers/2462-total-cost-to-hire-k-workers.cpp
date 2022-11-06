class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = size(costs);
        if(n == 1) return costs[0];
        
        long long minCost = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap1;
        priority_queue<int, vector<int>, greater<int>> minHeap2;
        int left = 0, right = n - 1, count = 0;
        
        while(count++ < k) {
            
            while(left <= right and size(minHeap1) < candidates)
                minHeap1.emplace(costs[left++]);
            while(left <= right and size(minHeap2) < candidates)
                minHeap2.emplace(costs[right--]);
            
            int top1 = size(minHeap1) > 0 ? minHeap1.top() : INT_MAX;
            int top2 = size(minHeap2) > 0 ? minHeap2.top() : INT_MAX;
            
            if(top1 <= top2) {
                minCost += minHeap1.top();
                minHeap1.pop();
            } else {
                minCost += minHeap2.top();
                minHeap2.pop();
            }
        }
        return minCost;
    }
};