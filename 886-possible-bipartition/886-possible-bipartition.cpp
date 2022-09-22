class Solution {
private:
    bool isBipartiteBFS(int src, vector<int> &color, vector<vector<int>> &adjList) {
        color[src] = 1;
        queue<int> q;
        q.emplace(src);
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            for(int adjNode: adjList[current]) {
                if(color[adjNode] == -1) {
                    color[adjNode] = 1 - color[current];
                    q.emplace(adjNode);
                } else if(color[adjNode] == color[current])
                    return false;
            }
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
            if(color[i] == -1 and !isBipartiteBFS(i, color, adjList))
                return false;
        return true;
    }
};