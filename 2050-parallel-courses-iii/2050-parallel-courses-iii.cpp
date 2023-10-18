/*

Idea

This problem is an advanced version of 1494. Parallel Courses II, which has prerequisite relationship between courses.
To solve prerequisite relationship, we can obviously use Topology Sort idea to complete prev courses before next courses.
Let dist[u] is the number of months required to finish u course, dist[u] is calculated as maximum dist of the predecessor nodes + times[u].

*/

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inDegree(n);
        vector<vector<int>> graph(n, vector<int>());
        for (const auto &edge : relations) {
            int prev = edge[0] - 1, next = edge[1] - 1;
            graph[prev].emplace_back(next);
            ++inDegree[next];
        }
        
        vector<int> dist(n);
        queue<int> q;
        for (int u = 0; u < n; ++u) {
            if (inDegree[u] == 0) {
                q.emplace(u);
                dist[u] = time[u];
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const int &v : graph[u]) {
                dist[v] = max(dist[v], dist[u] + time[v]); // Update `dist[v]` using the maximum dist of the predecessor nodes
                if (--inDegree[v] == 0) 
                    q.emplace(v);
            }
        }
        return *max_element(begin(dist), end(dist));
    }
};