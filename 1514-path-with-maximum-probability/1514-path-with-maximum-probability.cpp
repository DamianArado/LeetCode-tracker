class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Step 1: Construct the graph
        vector<vector<pair<int, double>>> graph(n);
        for(int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);            
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        // Step 2: Use a modified Dijkstra's algorithm for this
        priority_queue<pair<double, int>> maxHeap;
        vector<double> maxProb(n);
        
        maxHeap.emplace(1.0, start);
        maxProb[start] = 1.0;
        
        while(!maxHeap.empty()) {
            auto current = maxHeap.top().second;
            maxHeap.pop();
            for(auto &adjNode : graph[current]) {
                int nextNode = adjNode.first; 
                double nextProb = adjNode.second;
                if(maxProb[nextNode] < maxProb[current] * nextProb) {
                    maxProb[nextNode] = maxProb[current] * nextProb;
                    maxHeap.emplace(maxProb[nextNode], nextNode);
                }
            }
        }
        
        return maxProb[end];
    }
};