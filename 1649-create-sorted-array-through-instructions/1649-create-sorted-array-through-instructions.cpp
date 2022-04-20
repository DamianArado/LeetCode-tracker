class Solution {
//  Segment Tree Array
int tree[400040];
public:
    
    int get_mid(int a, int b) {
        return a + (b - a) / 2;
    }
    
	// Fn to get sum between range s to e
    int query(int index, int s, int e, int qs, int qe) {
		// 1. Base Case - Complete Overlapp
        if(s >= qs and e <= qe)
            return tree[index];
        
		// 2. Base Case - No overlapp
        if(e < qs or s > qe)
            return 0;
        
		// 3. Partial Overlapp
        int mid = get_mid(s, e);
        
        int leftAns = query(2*index + 1, s, mid, qs, qe);
        int rightAns = query(2*index + 2, mid + 1, e, qs, qe);
        
        return leftAns + rightAns;
    }
    
    void update(int index, int s, int e, int pos) {
        
		// 1. Base Case - Reached the node where update is required
        if(s == e) {
            tree[index]++;
            return;
        } 
		
		// 2. Intermidiate Node
        int mid = get_mid(s, e);
            
		if(pos <= mid) 
			update(2*index + 1, s, mid, pos);
		else
			update(2*index + 2, mid + 1, e, pos);

		tree[index] = tree[2*index + 1] + tree[2*index + 2];
    }
    
    int createSortedArray(vector<int>& instructions) {
        
        int cost = 0;
        const int MAXN = 1e5 + 1;
        const int MOD = 1e9 + 7;
        
        for(auto x : instructions) {
			// Get number of elements that are less than current element
            int less_count = query(0, 0, MAXN, 0, x - 1); 
			
			// Get number of elements which are greater than current element
            int greater_count = query(0, 0, MAXN, x + 1, MAXN); 
            
            update(0, 0, MAXN, x);
            
            cost = (cost + min(less_count, greater_count)) % MOD;
        }
        
        return cost; 
    }
};