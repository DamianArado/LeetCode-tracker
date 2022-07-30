// Time complexity: O(V+E)
// Space complexity: O(V)

class Solution {
  private:
    bool isCycleDFS(int current, int previous, vector<bool> &visited, vector<int> *adjList) {
        visited[current] = true;
        for(int adjNode : adjList[current]) {
            if(!visited[adjNode]) {
                if(isCycleDFS(adjNode, current, visited, adjList))
                    return true;
           } else if(adjNode != previous) 
                return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adjList[]) {
        vector<bool> visited(V, false);
        for(int i = 0; i < V; ++i) {
            if(!visited[i] and isCycleDFS(i, -1, visited, adjList))
                return true;
        }
        return false;
    }
};
