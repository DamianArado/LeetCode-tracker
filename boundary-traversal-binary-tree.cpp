/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };
Link: https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725
************************************************************/
// TC -> O(height) + O(height) + O(n) == O(n)
// SC -> O(n)

/*
    
    Approach here -
    
    1. Firstly, add the left boundary nodes by going towards root's left, excluding the leaf nodes by going left and
    if there is no left one go right.
    2. Add the leaf nodes by doing a simple preorder or inorder after checking whether it is
    a valid leaf node or not.
    3. Lastly, add the right boundary nodes in reverse order by going towards root's right and store the nodes
    in reverse order excluding the leaf nodes.
    
    */

bool isLeaf(TreeNode<int>* root) {
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode<int>* root, vector<int> &result) {
    TreeNode<int>* current = root->left;
    while(current) {
        if(!isLeaf(current)) result.emplace_back(current->data);
        if(current->left) current = current->left;
        else current = current->right;
    }
}

void addLeaves(TreeNode<int>* root, vector<int> &result) {
    if(isLeaf(root)) {
        result.emplace_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, result);
    if(root->right) addLeaves(root->right, result);
}

void addRightBoundary(TreeNode<int>* root, vector<int> &result) {
    TreeNode<int>* current = root->right;
    vector<int> temp;
    while(current) {
        if(!isLeaf(current)) temp.emplace_back(current->data);
        if(current->right) current = current->right;
        else current = current->left;
    }
    for(int i = temp.size() - 1; i >= 0; --i) result.emplace_back(temp[i]);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> result;
    if(!root) return result;
    if(!isLeaf(root)) result.emplace_back(root->data);
  
    addLeftBoundary(root, result);
    addLeaves(root, result);
    addRightBoundary(root, result);
    return result;
}
