class Solution {
private:
    void dfs(int current, vector<bool> &visited, vector<vector<int>>& isConnected, int n) {
        visited[current] = true;
        for(int i = 0; i < n; ++i)
            if(!visited[i] && isConnected[current][i] == 1)
                dfs(i, visited, isConnected, n);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), components = 0;
        vector<bool> visited(n, false);
        // lets perform DFS to calculate the no. of components
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfs(i, visited, isConnected, n);
                components += 1;
            }
        }
        return components;
    }
};