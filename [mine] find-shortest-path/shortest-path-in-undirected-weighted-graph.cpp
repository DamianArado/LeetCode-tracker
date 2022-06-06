// Time complexity: O((V+E)logV)
// Space complexity: O(V)

// We will use dijkstra's algorithm to find the shortest path from source to each node
// adjacency list is stored as a vector in format: [adjNode, edgeWt]
vector<int> dijkstra(vector<pair<int,int>> adjList[], int n, int source) {
	// priority queue as a min heap to store elements in form: [edgeWt, toVertex]
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	vector<int> distance(n, INT_MAX);
	vector<bool> visited(n, false);
	distance[source] = 0;
	// distance to source is the minimum as we start from here
	pq.push(make_pair(0, source));
	while(!pq.empty()) {
		int current = pq.top().second;  // node having the min distance currently
		pq.pop();
		for(auto adj : adjList[current]) {
			// shortest distance calculation
			if(distance[current] + adj.second < distance[adj.first]) {
				// adj.first -> adjNode, adj.second -> distanceToAdjNode
				distance[adj.first] = distance[current] + adj.second;
				// O(log V) operation to maintain min heap node at front
				pq.push(make_pair(distance[adj.first], adj.first));
			}
		}
	}
	return distance;
}
