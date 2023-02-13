class Solution {
private:
    int dfs(int current, int previous, const vector<vector<int>> &graph, long long &fuel, int seats) {
        int people = 1; // at any node the minimum representative
        for(const int &adjNode : graph[current]) {
            if(adjNode == previous) continue;
            // people that are arriving here from the leaf nodes
            people += dfs(adjNode, current, graph, fuel, seats);
        }
        // at any intermediate node this is the number of cars required
        if(current > 0)
            fuel += (people + seats - 1) / seats; // ceil(people / seats)
        return people;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // Step1: Create the graph
        vector<vector<int>> graph(size(roads) + 1);
        long long fuel = 0;
        for(const auto &road : roads) {
            graph[road[0]].emplace_back(road[1]);
            graph[road[1]].emplace_back(road[0]);
        }
        // Start doing DFS from the capital city
        dfs(0, -1, graph, fuel, seats);
        return fuel;
    }
};