/*
    How Segment Tree is helpful here?

    Segment is used to store the frequency of every element
    To get the count of elements less than x, we will make query Find sum between 0 to x-1
    To get the count of elements greater than x, we will make query Find sum between x+1 to 10^5 (As per constraints, it's maximum value)
    We can make each of these queries in logN time!
    
    */
/*  

Segment Tree based approach
class Solution {
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
*/
// Binary Indeced Tree-based approach
/*

    Idea

    Use Binary Indexed Tree structure bit to store count of elements in instructions array so far.
    For each x in instructions:
    left = bit.getSumRange(0, x - 1) : Get count of all numbers strickly less than x
    right = bit.getSumRange(x + 1, largest): Get count of all numbers strickly greater than x
    cost = (cost + min(left, right)) % 1_000_000_007
    bit.addValue(x, 1): Increase count of number x by one

    Complexity:

    Time: O(MLogM), wherer M is the maximum number in the array.
    Space: O(M)

*/
class BIT {
    vector<int> bit;
public:
    BIT(int size) {
        bit.assign(size + 1, 0);
    }
    int getSum(int idx) { // Get sum in range [0..idx], 1-based indexing
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
            sum += bit[idx];
        return sum;
    }
    int getSumRange(int left, int right) { // left, right inclusive, 1-based indexing
        return getSum(right) - getSum(left - 1);
    }
    void addValue(int idx, int val) { // 1-based indexing
        for (; idx < bit.size(); idx += idx & (-idx))
            bit[idx] += val;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int max = *max_element(instructions.begin(), instructions.end()), MOD = 1000000007;
        BIT bit(max);
        int cost = 0;
        for (int x : instructions) {
            int left = bit.getSumRange(0, x - 1);  // Get count of all numbers strictly less than x
            int right = bit.getSumRange(x + 1, max);  // Get count of all numbers strictly greater than x
            cost = (cost + min(left, right)) % MOD;
            bit.addValue(x, 1);  // Increase count of number x by one
        }
        return cost;
    }
};