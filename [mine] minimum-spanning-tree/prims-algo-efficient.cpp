// Here, we will an improved version of Prim's algorithm
// Time-complexity: O((V+E)*logV) = O(VlogV)
// Space-complexity: O(V)

void primsAlgoEfficient(vector<vector<pair<int,int>> adjList[], int n) {
	vector<int> minEdges(n, INT_MAX);
	vector<bool> mstSet(n, false);
	vector<int> parent(n, -1);
	// min heap to maintain the minimum cost edges : [minWeight, vertex]
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,0});
	// iterate over n - 1 edges
	for(int i = 0; i < n - 1; ++i) {
		// finding the vertex that can give us the min cost edge is now a O(1) operation
		int minCostVtx = pq.top().second;
		pq.pop();
		mstSet[minCostVtx] = true;
		for(auto adjNode : adjList[minCostVtx]) {
			int vertex = adjNode.first;
			int weight = adjNode.second;
			// update minEdges and parent for each adjacent node
			if(!mstSet[vertex] && weight < minEdges[vertex]) {
				minEdges[vertex] = weight;
				parent[vertex] = minCostVtx;
				pq.push({minEdges[vertex], vertex});  // O(log pq.size()) operation
			}
		}	
	}
	// we use the parent[] and minEdges[] to construct the minimum spanning tree
}

