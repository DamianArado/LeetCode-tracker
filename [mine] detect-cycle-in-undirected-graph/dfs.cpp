// Time complexity: O(V+E)
// Space complexity: O(V)

bool isCycleDFS(int current, int previous, vector<int> adjList[], vector<bool> &visited) {
	visited[current] = true;
	for(auto adj : current) {
		if(!visited[adj] && dfs(adj, current, adjList, visited))
			return true;
		else if(adj != previous)
			return true;
	}
	return false;
}

bool checkForCycle(vector<int> adjList[], int n) {
	vector<bool> visited(n + 1, false);
	for(int i = 1; i <= n; ++i) {
		// tracking the parent node implicitly
		if(!visited[i] && isCycleDFS(i, -1, adjList, visited)) {
			return true;
		}
	}
	return false;
}
