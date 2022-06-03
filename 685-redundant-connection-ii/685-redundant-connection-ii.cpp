class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        iota(begin(parent), end(parent), 0); // [0,1,2...n-1]
        rank.resize(n);
        fill(begin(rank), end(rank), 1);  // [1,1,1...upto n-1 times]
    }
    
    int findParent(int x) {
        if(x != parent[x])
            parent[x] = findParent(parent[x]);  // path compression
        return parent[x];  // found the parent himself
    }
    
    bool unionByRank(int a, int b) {
        int parentOfA = findParent(a), parentOfB = findParent(b);
        // if they belong to the same component, we cannot do a union
        if(parentOfA == parentOfB)
            return false;
        // make sure to update parent arrays!
        if(rank[a] > rank[b]) 
            parent[parentOfB] = parent[parentOfA];
        else if(rank[b] > rank[a])
            parent[parentOfA] = parent[parentOfB];
        else {
            // both the ranks are equal
            parent[parentOfB] = parent[parentOfA];
            rank[a] += 1;
        }
        return true;
    }
    
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n, 0), cand0, cand1, cand2;
        bool mult = false, cycle = false;
        UnionFind *uf = new UnionFind(n);
        for(auto &edge : edges) {
            int u = edge[0], v = edge[1];
            if(parent[v - 1]) {  // checking if its parent exists
                mult = true;  // it has multiple parents
                cand0 = {parent[v - 1], v};  // parent1
                cand1 = {u, v};  // parent2
            } else {
                parent[v - 1] = u;
                if(!uf->unionByRank(u - 1, v - 1)) {
                    cycle = true;
                    cand2 = {u, v};  // if cycle exists we get the parent3
                }
            }
        }
        // If multiple parent & cycle: return 1st parent, else if multiple parent only return 2nd parent, or else return the 3rd parent which will be empty
        return mult && cycle ? cand0 : mult ? cand1 : cand2;
    }
};