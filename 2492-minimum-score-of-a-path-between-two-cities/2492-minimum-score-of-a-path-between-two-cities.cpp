class Solution {
private:
    int dfs(int current, vector<bool> &visited, vector<vector<pair<int, int>>> &graph) {
        int minScore = INT_MAX;
        visited[current] = true;
        for(const auto &[next, distance] : graph[current]) {
            minScore = min(minScore, distance);
            if(!visited[next]) {
                visited[next] = true;
                minScore = min(minScore, dfs(next, visited, graph));
            }
        }
        return minScore;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Step 1: create a graph from the network of roads
        vector<vector<pair<int, int>>> graph(n + 1);
        for(const auto &road : roads) {
            graph[road[0]].emplace_back(road[1], road[2]);
            graph[road[1]].emplace_back(road[0], road[2]);
        }
        // Step 2: Perform a DFS starting from the city 1 and since it will have an edge 
        // connecting the last city, you are darn sure that you just need to track the min edge-weight
        // inside the component connecting city 1 and city n
        vector<bool> visited(n + 1);
        return dfs(1, visited, graph);
    }
};