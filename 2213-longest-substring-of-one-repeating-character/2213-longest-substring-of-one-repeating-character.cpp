/*

Quick Refresher
Segment tree is a logarithmic data structure that operates on a fixed-size array. Leaves of the segment tree are elements of the array, and non-leaf nodes hold some value of interest (sum, average, etc.) for the underlying segments.

Since updates and queries affect log(n) nodes, those operations have O(log n) complexity.

Segment tree can be implemented using an array of 2 * n size. You will need to know the index of the current node (root's index is zero), and left and right positions of the current segment. The left child index is i * 2 + 1, and the right child - i * 2 + 2. We also adjust left and right positions for the children. When left and right are equal - we've reached the leaf node.

Note that the size of the array n needs to be extended to be the power of 2.

Implementation
It is quite interesting on how to apply a segment tree to this problem. To find out the longest substring, we need to track repeating characters on the left (prefix), suffix, and max length. This is how the segment tree looks like for abbbbcc string:
image

For this problem, we do not need to query longest substring for an arbitrary range - only for the entire string. So, we only need the st_set operation.

The st_set first reaches the leaf node and sets the new characer, and then goes back and updates non-leaf nodes using the merge function.

*/

class Solution {
public:
    struct node {
        char lc = 0, rc = 0;
        int pref = 0, suf = 0, longest = 0, sz = 1;
        void merge(node &l, node &r) {
            longest = max(l.longest, r.longest);
            if (l.rc == r.lc)
                longest = max(longest, l.suf + r.pref);
            sz = l.sz + r.sz;
            lc = l.lc;
            rc = r.rc;
            pref = l.pref + (l.pref == l.sz && l.lc == r.lc ? r.pref : 0);
            suf = r.suf + (r.suf == r.sz && r.rc == l.rc ? l.suf : 0);
        } 
    };
    int st_set(vector<node>& st, int pos, char ch, int i, int l, int r) {
        if (l <= pos && pos <= r) {
            if (l != r) {
                auto m = l + (r - l) / 2, li = 2 * i + 1, ri = 2 * i + 2;
                st_set(st, pos, ch, li, l, m);
                st_set(st, pos, ch, ri, m + 1, r);
                st[i].merge(st[li], st[ri]);
            }
            else {
                st[i].lc = st[i].rc = ch;
                st[i].suf = st[i].pref = st[i].longest = 1;
            }
        }
        return st[i].longest;
    }    
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        vector<int> res;
        int powOf2 = 1, sz = s.size();
        while (powOf2 < sz) 
            powOf2 <<= 1;
        vector<node> st(powOf2 * 2);
        for (int i = 0; i < s.size(); ++i)
            st_set(st, i, s[i], 0, 0, powOf2 - 1);
        for (int j = 0; j < queryCharacters.size(); ++j)
            res.push_back(st_set(st, queryIndices[j], queryCharacters[j], 0, 0, powOf2 - 1));
        return res;
    }
};