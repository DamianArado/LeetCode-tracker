class Solution {
private:
    void dfs(int current, vector<bool> &visited, vector<vector<int>> &rooms) {
        visited[current] = true;
        for(int &adjRoom : rooms[current])
            if(!visited[adjRoom]) 
                dfs(adjRoom, visited, rooms);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = size(rooms);
        vector<bool> visited(n); 
        dfs(0, visited, rooms);
        for(int i = 0; i < n; ++i) if(!visited[i]) return false;
        return true;
    }
};