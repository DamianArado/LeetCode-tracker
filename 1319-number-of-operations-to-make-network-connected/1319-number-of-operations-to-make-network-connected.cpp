class Solution {
private:
    void dfs(int current, vector<bool> &visited, vector<vector<int>> &graph) {
        visited[current] = true;
        for(const auto &adjNode : graph[current])
            if(!visited[adjNode])
                dfs(adjNode, visited, graph);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // step 1: find the number of edges
        int numEdges = size(connections);
        if(numEdges < n - 1) return -1;
        // step 2: valid graph: construct the graph
        vector<vector<int>> graph(n);
        for(const auto &connection : connections) {
            graph[connection[0]].emplace_back(connection[1]);
            graph[connection[1]].emplace_back(connection[0]);
        }
        // step 3: check for the number of connected components using DFS
        int components = 0;
        vector<bool> visited(n);
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                ++components;
                dfs(i, visited, graph);
            }
        }
        return components - 1;
    }
};