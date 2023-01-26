class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: create the graph
        vector<pair<int, int>> graph[n];
        for(const auto &flight : flights) 
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        // Step 2: using basic BFS find shortest distance within k stops
        queue<pair<int, pair<int, int>>> q;
        vector<int> distances(n, INT_MAX);
        q.push({0, {src, 0}}); // stops, source, cost
        distances[src] = 0;
        while(!q.empty()) {
            auto it = q.front();
            int stops = it.first, node = it.second.first, cost = it.second.second;
            q.pop();
            if(stops > k) continue;
            for(const auto &[nextNode, nextCost] : graph[node]) {
                if(distances[nextNode] > cost + nextCost and stops <= k) {
                    distances[nextNode] = cost + nextCost;
                    q.push({stops + 1, {nextNode, distances[nextNode]}});
                }
            }
        }
        return distances[dst] != INT_MAX ? distances[dst] : -1;
    }
};