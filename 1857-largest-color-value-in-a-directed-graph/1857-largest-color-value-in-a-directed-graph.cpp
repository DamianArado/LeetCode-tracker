class Solution {
public:
    // Topological Sort (Kahn's algorithm)
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = size(colors);
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        vector<vector<int>> charCnt(n, vector<int> (26));  // to count the freq of characters
        // step 1: create the graph & indegree for bfs
        for (const auto &e : edges) {
            graph[e[0]].emplace_back(e[1]);
            ++indegree[e[1]];
        }
        // step2: start BFS
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 0)
                q.emplace(i);
        int numVisit = 0, largestPath = 0;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            ++numVisit;
            int currCharCnt = ++charCnt[current][colors[current] - 'a'];
            largestPath = max(largestPath, currCharCnt);
            for (const int &adjNode : graph[current]) {
                if (--indegree[adjNode] == 0) 
                    q.emplace(adjNode);
                for (int i = 0; i < 26; ++i)
                    charCnt[adjNode][i] = max(charCnt[adjNode][i], charCnt[current][i]);
            }
        }
        if (numVisit != n) return -1;
        return largestPath;
    }
};