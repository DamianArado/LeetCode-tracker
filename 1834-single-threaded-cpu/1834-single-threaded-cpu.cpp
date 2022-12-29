class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = size(tasks);
        if(n == 1) return {0};
        // minHeap: [processingTime, index]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // [enqueueTime, processingTime, index]
        for(int i = 0; i < n; ++i) tasks[i].emplace_back(i);
        // sort on the basis of increasing enqueue times
        sort(begin(tasks), end(tasks));
        long idx = 0, endTime = 0;
        vector<int> order;
        while(idx < n or !minHeap.empty()) {
            // if nothing in the heap start adding from the next enqueue time
            if(minHeap.empty())
                endTime = max(endTime, (long) tasks[idx][0]);
            // if some tasks start before or at the end time, add them to the available queue
            while(idx < n and endTime >= tasks[idx][0]) {
                minHeap.emplace(tasks[idx][1], tasks[idx][2]);
                idx++;
            }
            auto [time, index] = minHeap.top();
            minHeap.pop();
            order.emplace_back(index);
            endTime += time;
        }
        return order;
    }
};