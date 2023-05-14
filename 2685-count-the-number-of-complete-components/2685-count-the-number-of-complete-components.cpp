class Solution {
public:
    void dfs(vector<vector<int>> &graph, int current, vector<bool> &visited, int &nodeCount, int &edgeCount) {
        visited[current] = true;
        ++nodeCount;
        edgeCount += size(graph[current]);
        for(const int &nextNode : graph[current]) {
            if(!visited[nextNode]) {
                dfs(graph, nextNode, visited, nodeCount, edgeCount);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(vector<int> &edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        int ans = 0;
        vector<bool> visited(n);
        for(int i = 0; i < n; ++i) {
            int nodeCount = 0, edgeCount = 0;
            if(!visited[i]) {
                dfs(graph, i, visited, nodeCount, edgeCount);
                if((nodeCount*(nodeCount - 1)) == edgeCount) ++ans;
            }
        }
        return ans;
    }
};