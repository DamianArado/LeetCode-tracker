class DSU {
    vector<int> par, rank;
public:
    DSU(int n) : par(n), rank(n) {
        iota(begin(par), end(par), 0);
    }
    int find(int x) {
        if(x == par[x]) return x;                       // x is itself the parent of this component
        return par[x] = find(par[x]);                   // update parent of x before returning for each call
    }
    bool Union(int x, int y) {
        int xp = find(x), yp = find(y);                 // find parents of x and y, i.e, representatives of components that x and y belong to
        if(xp == yp) return false;                      // x and y already belong to same component - not possible to union
        if(rank[xp] > rank[yp]) par[yp] = par[xp];      // union by rank - join smaller ranked to bigger one
        else if(rank[yp] > rank[xp]) par[xp] = par[yp];
        else par[xp] = yp, rank[yp]++;                  // same rank - join either to other and increment rank of final parent
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        DSU ds(size(e) + 1);
        for(auto& E : e) 
            if(!ds.Union(E[0], E[1])) return E;	// not possible to union - adding this edge was causing the cycle
        return { };    // un-reachable
    }
};