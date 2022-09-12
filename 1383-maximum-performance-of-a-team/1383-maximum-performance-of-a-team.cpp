class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // Step 1: create an array to store an engineer's efficiency and speed
        // and sort this in increasing order act efficiency as we need to move from R -> L
        vector<pair<int, int>> engineer;
        for(int i = 0; i < n; ++i) 
            engineer.emplace_back(efficiency[i], speed[i]);
        sort(engineer.begin(), engineer.end());
        
        // Step 2: create a min heap to store the max sum of k engineer's speed
        // as soon as the elements inside the heap goes beyond k we would pop the min one
        // and we'll decrease the rolling sum as well
        // this works as our sum is still maximized and that will help us to maximize performance
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long sum = 0, ans = 0;
        for(int i = n - 1; i >= 0; --i) {
            sum += engineer[i].second;
            minHeap.emplace(engineer[i].second);
            if(size(minHeap) > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            ans = max(ans, sum * engineer[i].first);
        }
        
        return ans % ((int) 1e9 + 7);
    }
};