typedef long long ll;
class Solution {
private:
    void dfs(int src, vector<bool> &visited, vector<vector<int>> &graph, ll &count) {
        visited[src] = true;
        ++count;
        for(const int &adjNode : graph[src]) 
            if(!visited[adjNode])
                dfs(adjNode, visited, graph, count);
    }
public:
    ll countPairs(int n, vector<vector<int>>& edges) {
        // create graph
        vector<vector<int>> graph(n);
        for(const auto &e : edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        // total ways to make a pair out of n nodes - nC2
        ll total = (ll) n * (n - 1) / 2;
        // do a dfs, count nodes in each component and subtract those pairs from total
        vector<bool> visited(n);
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                // pair of nodes that are reachable
                ll count = 0;
                dfs(i, visited, graph, count);
                total -= (count * (count - 1) / 2);
            }
        }
        // remaining pair of nodes are unreachable
        return total;
    }
};