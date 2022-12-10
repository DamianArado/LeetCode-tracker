class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = size(vals), maxSum = INT_MIN;
        vector<vector<pair<int, int>>> adjList(n);
        for(auto &edge : edges) {
            adjList[edge[0]].emplace_back(edge[1], vals[edge[1]]);
            adjList[edge[1]].emplace_back(edge[0], vals[edge[0]]);
        }
        for(int i = 0; i < n; ++i) {
            int sum = vals[i], k0 = k;
            priority_queue<int> maxHeap;
            for(auto &edge : adjList[i])
                if(edge.second > 0) 
                    maxHeap.emplace(edge.second);
            while(!maxHeap.empty() and k0--) {
                sum += maxHeap.top();
                maxHeap.pop();
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};