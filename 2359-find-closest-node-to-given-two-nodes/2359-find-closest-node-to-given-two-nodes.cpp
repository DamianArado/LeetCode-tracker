class Solution {
private:
    vector<int> findShortestDistance(vector<vector<int>> &graph, int node) {
        int n = size(graph);
        vector<int> distances(n, INT_MAX);
        queue<int> q;
        distances[node] = 0;
        q.emplace(node);
        while(!q.empty()) {
            int n = size(q);
            for(int i = 0; i < n; ++i) {
                int current = q.front();
                q.pop();
                for(int &adjNode : graph[current]) {
                    if(distances[adjNode] > distances[current] + 1) {
                        distances[adjNode] = 1 + distances[current];
                        q.emplace(adjNode);
                    }
                }
            }
        }
        return distances;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = size(edges);
        // Step 1: Construct the graph
        vector<vector<int>> graph(n);
        for(int i = 0; i < size(edges); ++i)
            if(edges[i] != -1) 
                graph[i].emplace_back(edges[i]);
        // Step 2: Find shortest distance from node1 to all other nodes in the graph
        vector<int> shortestDist1 = findShortestDistance(graph, node1);
        vector<int> shortestDist2 = findShortestDistance(graph, node2);
        int minDist = INT_MAX, minNode = -1;
        for(int i = 0; i < n; ++i) {
            if(shortestDist1[i] != INT_MAX and shortestDist2[i] != INT_MAX) {
                if(minDist > max(shortestDist1[i], shortestDist2[i])) {
                    minDist = max(shortestDist1[i], shortestDist2[i]);
                    minNode = i;
                }
            }
        }
        return minNode;
    }
};