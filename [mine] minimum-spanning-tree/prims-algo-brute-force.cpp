// Here, we will find out the minimum spanning tree using Prim's algorithm
// Time-complexity: O((V)*(V+E)) = O(V^2)
// Space-complexity: O(V)

void primsAlgoBrute(vector<vector<pair<int,int>> adjList[], int n) {
	vector<int> minEdges(n, INT_MAX);
	vector<bool> mstSet(n, false);
	vector<int> parent(n, -1);
	minEdges[0] = 0;
	// iterate over n - 1 edges
	for(int i = 0; i < n - 1; ++i) {
		// calculate minimum cost edge and the vertex
		int minCostEdge = INT_MAX, minCostVtx;
		// find the minimum cost edge among all the vertices
		for(int minVtx = 0; minVtx < n; ++minVtx) {
			if(!mstSet[minVtx] && minEdges[minVtx] < minCostEdge) 
				minCostEdge = minEdges[minVtx], minCostVtx = minVtx;
			// found the vertex that will contribute the minimum cost edge
			mstSet[minCostVtx] = true;
			// now update minEdges and parent for each adjacent node
			for(auto adjNode : adjList[minCostVtx]) {
				int vertex = adjNode.first;
				int weight = adjNode.second;
				if(!mstSet[vertex] && weight < minEdges[vertex]) {
					minEdges[vertex] = weight;
					parent[vertex] = minCostVtx;
				}
			}
		}
	}
	// we use the parent[] and minEdges[] to construct the minimum spanning tree
}

