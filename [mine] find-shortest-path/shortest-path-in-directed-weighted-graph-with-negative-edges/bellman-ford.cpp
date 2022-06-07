// To find shortest distance from source to all nodes in a directed graph which has negative edge weights
// Bellman ford will not work if the graph has a negative cycle
// When used with undirected graphs, it has to be converted to directed graph
// TC - O(VE), SC - O(1)

struct node {
	int u, v, wt;
	node(int _u, int _v, int _wt) {
		u = _u, v = _v, wt = _wt;
	}
};

void bellmanFord(vector<node> edges, int source, int n) {
	vector<int> shortestDist(n, INT_MAX);
	shortestDist[source] = 0;
	// Step 1: relax each of the edge in the edge list n - 1 times
	for(int i = 0; i < n - 1; ++i) {
		for(auto edge : edges) {
			if(shortestDist[edge.u] + edge.wt < shortestDist[edge.v])
				shortestDist[edge.v] = shortestDist[edge.u] + edge.wt;
		}
	}
	// Step 2: If the distances decrease again, there is a negative cycle
	bool negCycle = false;
	for(auto edge : edges) {
		if(shortestDist[edge.u] + edge.wt < shortestDist[edge.v]) {
			cout << "Negative Cycle!"
			negCycle = true;
			break;
		}		
	}
	// Step 3: If there is no negative cycle, you got the shortest distances
	if(!negCycle) {
		for(int i = 0; i < n; ++i) 
			cout << i << " " << shortestDist[i] << “ “;
	}
}
