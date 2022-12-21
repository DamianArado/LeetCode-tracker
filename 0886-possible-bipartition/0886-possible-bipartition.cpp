class Solution {
private:
    bool isBipartiteDFS(int current, vector<int> &color, vector<vector<int>> &adjList) {
        if(color[current] == -1) color[current] = 1;
        for(int &adjNode: adjList[current]) {
            if(color[adjNode] == -1) {
                color[adjNode] = 1 - color[current];
                if(!isBipartiteDFS(adjNode, color, adjList))
                    return false;
            } else if(color[adjNode] == color[current])
                return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n + 1);
        for(int i = 0; i < size(dislikes); ++i) {
            adjList[dislikes[i][0]].emplace_back(dislikes[i][1]);
            adjList[dislikes[i][1]].emplace_back(dislikes[i][0]);
        }
        vector<int> color(n + 1, -1);
        for(int i = 1; i <= n; ++i) 
            if(color[i] == -1 and !isBipartiteDFS(i, color, adjList))
                return false;
        return true;
    }
};