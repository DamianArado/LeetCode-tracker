// Time complexity: O(V+E)
// Space complexity: O(V)

// In this problem, we will find shortest path in an unweighted (having unit weights) undirected graph
// We will use a modified BFS algorithm to find the shortest distance from source to all other nodes

vector<int> shortestDistanceUnweighted(vector<int> adjList[], int n, int source) {
	vector<int> distance(n + 1, INT_MAX);
	queue<int> q;
	q.push(source);
	distance[source] = 0;
	while(!q.empty()) {
		int current = q.front();
		q.pop();
		for(auto adj : adjList[current]) {
			if(distance[current] + 1 < distance[adj]) {
				distance[adj] = distance[current] + 1;
				q.push(adj);
			}
		}
	}
	return distance;
}
