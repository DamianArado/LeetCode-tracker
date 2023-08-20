class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> graph(n + m);
        vector<int> indegree(n + m, 0);
        for (int i = 0; i < group.size(); i++) {
            if (group[i] == -1) continue;
            graph[n+group[i]].push_back(i);
            indegree[i]++;
        }
        for (int i = 0; i < beforeItems.size(); i++) {
            for (const int &e : beforeItems[i]) {
                int a = group[e] == -1 ? e : n + group[e];
                int b = group[i] == -1 ? i : n + group[i];
                if (a == b) { // same group, ingroup order
                    graph[e].push_back(i);
                    indegree[i]++;
                } else { // outgroup order
                    graph[a].push_back(b);
                    indegree[b]++;
                }
            }
        }
        vector<int> ans;
        for (int i = 0;i < n + m;i++) 
            if (indegree[i] == 0)
                dfs(ans, graph, indegree, n, i);
        return ans.size() == n ? ans : vector<int> {};
    }
    
    void dfs(vector<int>& ans, vector<vector<int>>& graph, vector<int>& indegree, int n, int cur) {
        if (cur < n) 
            ans.emplace_back(cur);
        indegree[cur] = -1; // mark it visited
        for (const auto &next : graph[cur]) {
            indegree[next]--;
            if (indegree[next] == 0)
                dfs(ans, graph, indegree, n, next);
        }
    }
};