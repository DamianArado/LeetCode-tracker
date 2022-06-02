/***

(Union By Rank and Find with path Compression)

This optimization involves doing the union based on the rank (or size) of parents / representative of a 
component instead of just attaching one to the other randomly. This will ensure that even in the worst-case, 
we don't end up in a scenario where the par forms a skewed tree (all nodes on one-side) and we wouldn't need 
to iterate all nodes on each find call. Performing the union based on rank will keep the components/tree 
balanced in size.

Time Complexity : O(n*α(n)) ≈ O(n), the time complexity of each find call after union-by-rank and path 
compression comes out to be O(α(n)), where α(n) is the inverse Ackermann function. It doesn't exceed 4 for 
any n < 10600 and hence is practically constant. We make O(n) calls in total.

Space Complexity : O(n)

**/

class DSU {
    vector<int> parent, rank;
public:
    // initializing
    DSU(int n) : parent(n), rank(n) {
        iota(begin(parent), end(parent), 0);
    }
    
    // Find with Path compression
    int findParent(int x) {
        if(x == parent[x])  // if x is equal to its parent itself
            return x;
        return parent[x] = findParent(parent[x]);  // path-compression
    }
    
    // Union by RANK operation
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
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        DSU dsu(size(e) + 1); // initializing our disjoint set union data structure
        for(auto &edge : e) {
            if(!dsu.unionByRank(edge[0], edge[1]))  // they belong to the same component already
                return edge;
        }
        return {};
    }
};