// // Solution 1: uses a visited array
// class Solution {
// private:
//     int dfs(int source, vector<vector<int>> &graph, vector<bool> &visited) {
//         visited[source] = true;
//         int count = 0;
//         for(const int &adjNode : graph[source])
//             if(!visited[abs(adjNode)])
//                 count += ((adjNode > 0) + dfs(abs(adjNode), graph, visited));
//         return count;
//     }
// public:
//     int minReorder(int n, vector<vector<int>>& connections) {
//         // step 1: build the graph with nodes: +ve for front edge and -ve for back edge
//         vector<vector<int>> graph(n);
//         for(const auto &c : connections) {
//             graph[c[0]].emplace_back(c[1]);
//             graph[c[1]].emplace_back(-c[0]);
//         }
//         vector<bool> visited(n, false);
//         return dfs(0, graph, visited);
//     }
// };

// Solution 2: Uses just the edges and count how many of them need to be reversed
class Solution {
private:
    void dfs(int source, int parent, vector<vector<pair<int, int>>> &graph, int &reversed) {
        for(const auto &adjNode : graph[source]) {
            if(adjNode.first == parent) continue;
            reversed += adjNode.second;
            dfs(adjNode.first, source, graph, reversed);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for(const auto &c : connections) {
            graph[c[0]].emplace_back(c[1], 1);
            graph[c[1]].emplace_back(c[0], 0);
        }
        int reversed = 0;
        dfs(0, -1, graph, reversed);
        return reversed;
    }
};