class Solution {
// TC and SC: O(E)
private:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int current, int end) {
        if(current == end) return true;
        if(visited[current]) return false;
        visited[current] = true;
        for(int i = 0; i < graph[current].size(); ++i) {
            if(dfs(graph, visited, graph[current][i], end))
                return true;
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n);
        return dfs(graph, visited, start, end);
    }
};