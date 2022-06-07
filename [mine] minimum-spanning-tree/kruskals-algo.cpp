// Here, we will use Kruskal's algo to find the minimum cost spanning tree
// Time-complexity: O(VlogV + V*4alpha) = O(VlogV)
// Space-complexity: O(V)

struct node {
	int u, v, wt;
	node(int start, int end, int weight) {
		u = start, v = end, wt = weight;
	}
};

bool comparator(node a, node b) {
	return a.wt < b.wt;
}

int findParent(int x, vector<int> &parent) {
	if(x == parent[x])
		return x;
	return parent[x] = findParent(parent[x], parent);  // path compression
}

bool union(int a, int b, vector<int> &parent, vector<int> &rank) {
	int pA = findParent(a, parent), pB = findParent(b, parent);
	if(pA == pB) 
		return false;
	// union by rank
	if(rank[a] > rank[b])
		parent[b] = a;
	else if(rank[b] > rank[a])
		parent[a] = b;
	else 
		parent[b] = a, rank[a]++;
	return true;
}

void kruskalsAlgo(vector<node> &edges, int n) {
	// sorting the edges on the basis of increasing weights
	sort(begin(edges), end(edges), comparator);
	vector<int> parent(n);
	iota(begin(parent), end(parent), 0);
	vector<int> rank(n, 0);
	int minCost = 0;
	vector<pair<int,int>> mst;
	// iterate over all the edges from u -> v
	for(auto it : edges) {
		if(union(it.u, it.v)) {
			minCost += it.wt;
			mst.emplace_back(it.u, int.v);
		}
	}
}
