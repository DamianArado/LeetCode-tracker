class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // Step1: Create a graph of type node - (adjNode, edgeColor)
        vector<vector<pair<int, int>>> graph(n);
        for(auto &e : redEdges) graph[e[0]].emplace_back(e[1], 0);
        for(auto &e : blueEdges) graph[e[0]].emplace_back(e[1], 1);
        
        // Step2: Perform a BFS traversal for shortest distance to each node
        vector<int> distance(n, -1);
        distance[0] = 0;
        vector<vector<bool>> visited(n, vector<bool> (2));  // <node, edgeColor>
        visited[0][0] = visited[0][1] = true;
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, -1);  // <node, distance, color
        
        while(!q.empty()) {
            auto [currNode, currDist, currColor] = q.front();
            q.pop();
            for(auto &[nextNode, nextColor] : graph[currNode]) {
                if(!visited[nextNode][nextColor] and nextColor != currColor) {
                    visited[nextNode][nextColor] = true;
                    q.emplace(nextNode, currDist + 1, nextColor);
                    if(distance[nextNode] == -1)
                        distance[nextNode] = currDist + 1;
                }
            }  
        }
        return distance;
    }
};