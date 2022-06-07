// Here, we will use Kosaraju algorithm to find the strongly-connected components
// TC & SC: O(V+E)

void dfs(int current, vector<bool> &visited, vector<int> adjList[], stack<int> &topo) {
	visited[current] = true;
	for(auto adjNode : adjList[current]) {
		if(!visited[adjNode])
			dfs(adjNode, visited, adjList, topo);
	}
	topo.push(current);
}

void reverseDFS(int current, vector<bool> &visited, vector<int> transpose[]) {
	cout << current << “ “;
	visited[current] = true;
	for(auto adjNode : transposecurrent]) {
		if(!visited[adjNode])
			reverseDFS(adjNode, visited, transpose);
	}
}

void kosarajuSCC(vector<int> adjList[], int n) {
	vector<bool> visited(n, false);
	stack<int> topo;  // to store the topological sort order
	// Step 1: Sorting the nodes in order of their finishing time (Topological sort ordering)
	for(int i = 0; i < n; ++i) {
		if(!visited[i])
			dfs(i, visited, adjList, topo);
	}
	// Step 2: Doing the transpose (reversing the edges of the graph)
	// This is to make sure we don’t end up visiting the other SCC(s) except the current one
	vector<int> transpose[n];
	for(int i = 0; i < n; ++i) {
		visited[i] = false;
		for(auto adj : adjList[i]) 
			transpose[adj].push_back(i);
	}

	// Step 3: Perform DFS on the transposed graph in order to return the SCC(s)
	for(int i = 0; i < n; ++i) {
		if(!visited[i]) {
			reverseDFS(i, visited, transpose);
			cout << “\n”;
		}
	}
}
