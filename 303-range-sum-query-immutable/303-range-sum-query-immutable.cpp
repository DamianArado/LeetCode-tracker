class NumArray {
    vector<int> segTree;
    inline static int n;
    
    void buildTree(vector<int> &nums, int nodeIdx, int l, int r) {
        if(l == r) segTree[nodeIdx] = nums[l];
        else {
            int mid = l + (r - l) / 2;
            buildTree(nums, 2 * nodeIdx, l, mid);
            buildTree(nums, 2 * nodeIdx + 1, mid + 1, r);
            segTree[nodeIdx] = segTree[2 * nodeIdx] + segTree[2 * nodeIdx + 1];
        }
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n, 0);
        buildTree(nums, 1, 0, n - 1);
    }
    
    int sumRange(int left, int right, int nodeIdx = 1, int l = 0, int r = n - 1) {
        if(left > right) return 0;
        if(left == l && right == r) return segTree[nodeIdx];
        int mid = l + (r - l) / 2;
        return sumRange(left, min(right, mid), 2 * nodeIdx, l, mid) + sumRange(max(left, mid + 1), right, 2 * nodeIdx + 1, mid + 1, r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */