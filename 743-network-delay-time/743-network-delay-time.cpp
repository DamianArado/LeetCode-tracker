typedef pair<int,int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: construct the graph
        vector<vector<pii>> graph(n + 1);
        for(const auto &time : times)
            graph[time[0]].emplace_back(time[1], time[2]);
        
        // Step 2: construct the min heap
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        minHeap.emplace(0, k);
        
        // Step 3: construct our distance array using dijsktra's algorithm
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        while(!minHeap.empty()) {
            int u = minHeap.top().second;
            minHeap.pop();
            for(const auto &adjNode : graph[u]) {
                int v = adjNode.first, w = adjNode.second;
                if(distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                    minHeap.emplace(distance[v], v);
                }
            }
        }
        
        // Step 4: find out the min time for all nodes to recieve the signal
        int time = *max_element(distance.begin() + 1, distance.end());
        return time == INT_MAX ? -1 : time;
    }
};