// Time complexity: O(V+E)
// Space complexity: O(V)
// We are using Kahn’s algorithm that uses BFS under the hood
vector<int> topologicalSort(vector<int> adjList[], int n) {
	vector<int> indegree(n, 0);
	for(int i = 1; i <= n; ++i) {
		for(auto adj : adjList[i])
			indegree[adj] += 1;
	}
	// The intuition is to always start with a node with indegree = 0, and gradually add nodes
	// in the increasing order of the indegrees
	// We also reduced the indegrees of a particular node when we examined the edge on which it lies
	for(int i = 1; i <= n; ++i) 
		if(indegree[i] == 0)
			 q.push(i);
	// Take items from the queue and add it in the topological ordering
	while(!q.empty()) {
		int current = q.front();
		q.pop();
		topologicalOrdering.push_back(current);
		for(auto adj : adjList[current]) {
			indegree[adj] -= 1;
			if(indegree[adj] == 0)
				q.push(adj);
		}
	}
	return topologicalOrdering;
}

