/*
TC - Initial segment tree construction: O(n), update and sumRange: O(log n)
SC - O(n)
*/

class NumArray {
private:
    vector<int> segTree;
    inline static int n;
    
    void buildSegTree(vector<int> &nums, int nodeIdx, int l, int r) {
        if(l == r) {
            segTree[nodeIdx] = nums[l];
            return;
        } else {
            int mid = l + (r - l) / 2;
            buildSegTree(nums, 2 * nodeIdx, l, mid);
            buildSegTree(nums, 2 * nodeIdx + 1, mid + 1, r);
            segTree[nodeIdx] = segTree[2 * nodeIdx] + segTree[2 * nodeIdx + 1];
        }
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n, 0);
        buildSegTree(nums, 1, 0, n - 1);
    }
    
    void update(int index, int val, int nodeIdx = 1, int l = 0, int r = n - 1) {
        if(l == r) {
            segTree[nodeIdx] = val;
        } else {
            int mid = l + (r - l) / 2;
            if(index <= mid) update(index, val, 2 * nodeIdx, l, mid);
            else update(index, val, 2 * nodeIdx + 1, mid + 1, r);
            segTree[nodeIdx] = segTree[2 * nodeIdx] + segTree[2 * nodeIdx + 1];
        }
    }
    
    int sumRange(int left, int right, int nodeIdx = 1, int l = 0, int r = n - 1) {
        if(left > right) return 0;
        if(left == l && right == r) return segTree[nodeIdx];
        
        int mid = l + (r - l) / 2;
        return sumRange(left, min(right, mid), 2 * nodeIdx, l, mid) 
            + sumRange(max(left, mid + 1), right, 2 * nodeIdx + 1, mid + 1, r);
    }
};