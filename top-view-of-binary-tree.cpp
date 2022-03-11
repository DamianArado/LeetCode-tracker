/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// TC -> O(n) SC -> O(n)
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(!root) return ans;
    map<int, int> omp; // stores the vertical line and the first node on it (when seen from the top view)
    queue<pair<TreeNode<int>*, int>> q; // stores the node and the level on which it is (-2, 1, etc)
    q.push({root, 0}); // insert the root at first
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode<int>* node = it.first;
        int vLine = it.second;
        if(omp.find(vLine) != omp.end()) omp[vLine] = node->val;
        if(node->left) q.push({node->left, vLine - 1});
        if(node->right) q.push({node->right, vLine + 1});
    }
    for(auto it : omp) ans.emplace_back(it.second);
    return ans;
}
