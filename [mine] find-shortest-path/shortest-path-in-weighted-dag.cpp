// Time complexity: O(V+E)
// Space complexity: O(V)

// We will try to find out the shortest distance from source to each node 
// in a weighted DAG
void findTopologicalSortOrder(int current, vector<pair<int,int>> adjList[], stack<int> &topo, vector<bool> &visited) {
	visited[current] = true;
	for(auto adj : adjList[current]) {
		if(!visited[adj])
			findTopologicalSortOrder(adj, adjList, topo, visited);
	}
	topo.push(current);
}

// adjacency list is taken as an array of [adjNode,edgeWt]
vector<int> shortestPathDAG(vector<pair<int,int>> adjList[], int n, int source) {
	vector<int> distance(n, INT_MAX);  // to store shortest distances
	vector<bool> visited(n, false);
	stack<int> topo;  // to store topological sort order
	for(int i = 0; i < n; ++i) {
		if(!visited[i])
			findTopologicalSortOrder(i, adjList, topo, visited);
	}
	distance[source] = 0;
	// we will now move according to the topological ordering
	while(!topo.empty()) {
		int current = topo.top();
		topo.pop();
		// checking whether we have reached that node or not
		if(distance[current] != INT_MAX) {
			// if only we are standing at that node
			for(auto adj : adjList[current]) {
					// calculation of shortest distance
					if(distance[current] + adj.second < distance[adj.first]) {
						distance[adj.first] = distance[current] + adj.second;
					}
			}
		}
	}
	return distance;
}
