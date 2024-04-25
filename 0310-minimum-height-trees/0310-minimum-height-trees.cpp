class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (!size(edges)) return {0};
        // Step 1: Construct the undirected graph
        vector<vector<int>> graph(n);
        for (const auto &edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        // find the leaf nodes
        vector<int> leaves, newLeaves, inDegree;
        for (int i = 0; i < n; ++i) {
            // a node having only one adjacent node is a leaf node
            if (size(graph[i]) == 1)
                leaves.emplace_back(i);
            // indegree of a node = no. of adjacent nodes
            inDegree.emplace_back(size(graph[i]));
        }
        // continue the process till we have only 2 or 1 leaf nodes
        int numTrees = n;
        while (numTrees > 2) {
            for (const int &leaf : leaves) {
                for (const int &adjNode : graph[leaf])
                    if (--inDegree[adjNode] == 1)
                        newLeaves.emplace_back(adjNode);
            }
            numTrees -= size(leaves);
            leaves = move(newLeaves);
        }
        // the last 1 or 2 leaf nodes is our answer
        return leaves;
    }
};