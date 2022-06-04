// Time complexity: O(V+E)
// Space complexity: O(V)
// There can be multiple topological orderings for a given Directed Acyclic Graph (DAG)
void getTopologicalOrdering(int current, vector<int> adjList[], vector<bool> &visited, stack<int> &s) {
	visited[current] = true;
	for(auto adj : adjList[current]) {
		if(!visited[adj])
			getTopologicalOrdering(adj, adjList, visited, s);
	}
	s.push(current);
}

vector<int> topologicalSort(vector<int> adjList[], int n) {
	vector<bool> visited(n + 1, false);
	stack<int> s;
	for(int i = 1; i <= n; ++i) {
	if(!visited[i])
		getTopologicalOrdering(i, adjList, visited, s);
	}
	vector<int> topologicalOrdering;
	while(!s.empty()) {
		topologicalOrdering.push_back(s.top());
		s.pop();
	}
	return topologicalOrdering;
}

