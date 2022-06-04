// Time complexity: O(V+E)
// Space complexity: O(V)

bool isCycleDFS(int current, vector<int> adjList[], vector<bool> &visited, vector<bool> &dfsVisit) {
	visited[current] = dfsVisit[current] = true;
	for(auto adj : adjList[current]) {
		if(!visited[adj] && isCycleDFS(current, adjList, visited, dfsVisit))
			return true;
		// already visited in the current DFS call
		else if(dfsVisit[adj])
			return true;
	}
	// current DFS call ends
	dfsVisit[current] = false;
	return false;
}

bool detectCycle(vector<int> adjList[], int n) {
	vector<bool> visited(n + 1, false), dfsVisit(n + 1, false);
	for(int i = 1; i <= n; ++i) {
		if(!visited[i] && isCycleDFS(i, adjList, visited, dfsVisit))
			return true;
	}
	return false;
}
