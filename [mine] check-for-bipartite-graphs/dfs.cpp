// Time complexity: O(V+E)
// Space complexity: O(V)

bool bipartiteDFS(int current, vector<int> adjList[], vector<int> &color) {
	// this will happen only once
	if(color[current] == -1)
		color[current] == 1;	
	for(auto adj : adjList[current]) {
		if(color[adj] == -1) {
			color[adj] = 1 - color[current];
			if(!bipartiteDFS(adj, adjList, color))
				return false;
		} else if(color[adj] == color[current]) {
			return false;
		}
	}
	return true;
}

bool checkIfBipartite(vector<int> adjList[], int n) {
	vector<int> color(n + 1, -1);
	for(int i = 1; i <= n; ++i) {
		if(color[i] == -1 && !bipartiteDFS(i, adjList, color)) 
			return false;
	}
	return true;
}
