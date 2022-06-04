// Time complexity: O(V+E)
// Space complexity: O(V)

bool bipartiteBFS(int source, vector<int> adjList[], vector<int> &color) {
	color[source] = 1;  
	queue<int> q;
	q.push(source);
	while(!q.empty()) {
		int current = q.front();
		q.pop();
		for(auto adj : adjList[current]) {
			if(color[adj] == -1) {
				color[adj] = 1 - color[current];
				q.push(adj);
			} else if(color[adj] == color[current]) {
				return false;
			}
		}
	}
	return true;
}

bool checkForBipartite(vector<int> adjList[], int n) {
	// all vertices are colored with -1 at the start
	// coloring adjacent nodes with 1 and 0
	vector<int> color(n + 1, -1);
	for(int i = 1; i <= n; ++i) {
		if(color[i] == -1 && !bipartiteBFS(i, adjList, color))
			return false;
	}
	return true;
}
