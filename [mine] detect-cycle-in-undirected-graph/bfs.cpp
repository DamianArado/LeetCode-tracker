// Time complexity: O(V+E)
// Space complexity: O(V)

bool isCycleBFS(int current, vector<int> adjList[], vector<bool> &visited) {
    visited[current] = true;
    // elements inside the queue are in the format: [current, previous]
    // tracking the parent node explicitly
    queue<pair<int,int>> q;
    q.push({current, -1});  
    while(!q.empty()) {
        int curr = q.front().first;
        int prev = q.front().second;
        q.pop();
        for(auto adj : adjList[current]) {
            if(!visited[adj]) {
                q.push({adj, current});
                visited[adj] = true;
            } else if(adj != prev) {
                return true;
            }
        }
    }
    return false;
}

bool checkForCycle(vector<int> adjList[], int n) {
    vector<bool> visited(n + 1, false);
    for(int i = 1; i <= n; ++i) {
        if(!visited[i] && isCycleBFS(i, adjList, visited)) 
            return true;
        }
    return false;
}
