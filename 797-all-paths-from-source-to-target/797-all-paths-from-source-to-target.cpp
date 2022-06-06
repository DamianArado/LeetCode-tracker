class Solution {
public:
    // Using class variables instead of supplying members in every dfs call in order to have a lighter call stack
    int target;  // as it says
    vector<int> path;  // to store a path from source to target
    vector<vector<int>> result;  // to store all paths from source to target
    // target gets reinitiated in every class instance
    // path gets cleaned up the end of every DFS call
    
    void dfs(vector<vector<int>> &graph, int current = 0) {
        path.push_back(current);
        // if we reached the destination, push this path in result
        if(current == target)
            result.push_back(path);
        // else move on to its adjacent nodes
        else for(int adjNode : graph[current])
            dfs(graph, adjNode);
        // at the end of each DFS call, remove the current node from the path (Backtracking)
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size() - 1;
        dfs(graph);
        return result;
    }
};