// Solution 1: uses a visited array
class Solution {
private:
    int dfs(int source, vector<vector<int>> &graph, vector<bool> &visited) {
        visited[source] = true;
        int count = 0;
        for(const int &adjNode : graph[source])
            if(!visited[abs(adjNode)])
                count += ((adjNode > 0) + dfs(abs(adjNode), graph, visited));
        return count;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // step 1: build the graph with nodes: +ve for front edge and -ve for back edge
        vector<vector<int>> graph(n);
        for(const auto &c : connections) {
            graph[c[0]].emplace_back(c[1]);
            graph[c[1]].emplace_back(-c[0]);
        }
        vector<bool> visited(n, false);
        return dfs(0, graph, visited);
    }
};