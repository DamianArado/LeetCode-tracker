class Solution {
// Point to remember: A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B
// Here we are using the fact that in a bipartite graph no 2 adjacent nodes will be colored with the same color (1 or 0 for example)
// TC: O(V + E), SC: O(V)
private:
    bool isBipartiteDFS(int current, vector<vector<int>> &graph, vector<int> &color) {
        // if it is not yet colored, color it with 1
        if(color[current] == -1) color[current] = 1;
        // check Bipartite condition among the adjacent nodes
        for(int &adjNode : graph[current]) {
            // color the adjacent node with the opposite color if its not yet colored
            if(color[adjNode] == -1) {
                color[adjNode] = 1 - color[current];
                // now check for the condition via DFS call
                if(!isBipartiteDFS(adjNode, graph, color))
                    return false;
            } else if(color[adjNode] == color[current]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; ++i) {
            if(color[i] == -1 and !isBipartiteDFS(i, graph, color))
                return false;
        }
        return true;
    }
};