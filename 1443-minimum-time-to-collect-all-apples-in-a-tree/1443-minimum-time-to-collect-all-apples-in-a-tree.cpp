class Solution {
private:
    int dfs(int current, int parent, vector<vector<int>> &g, vector<bool> &hasApple) {
        int total = 0;
        for(int &adjNode : g[current]) {
            if(adjNode == parent) continue;
            total += dfs(adjNode, current, g, hasApple);
        }
        if(current != 0 and (total > 0 or hasApple[current]))
            total += 2;
        return total;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> g(n);
        for(int i = 0; i < size(edges); ++i) {
            g[edges[i][0]].emplace_back(edges[i][1]);
            g[edges[i][1]].emplace_back(edges[i][0]);
        }
        return dfs(0, 0, g, hasApple);
    }
};