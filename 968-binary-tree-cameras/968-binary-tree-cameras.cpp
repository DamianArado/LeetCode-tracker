/**
 Approach - 
 
 Consider a node in a tree. It can be covered by its parent, itself or its two children (4 options).
 Consider the root of a tree. It can be covered by its left & right child or itself (3 options).
 Consider leaf of a tree. It can be covered by its parent or itself (2 options).
 
 If we set a camera at the leaf, the camera can cover the leaf and its parent. If we set a camera at 
 its parent, the camera can cover the leaf, its parent and its sibling. So, better would be to set a 
 camera to all the leaves' parents. 
 
 Here is the greedy approach:
 1. Set camera on all leaves' parents then, remove all covered nodes
 2. Repeat step 1 until all nodes are covered
 
 For this, we will apply a recursive fxn dfs: Return 0 if its a leaf, 1 if its a parent of a leaf 
 with a camera on this node and 2 if its covered without a camera on this node.
 
 For each node, if it has a child, which is a leaf (node 0), then it needs a camera.
 If it has a child which is the parent of a leaf (node 1), then its covered. 
 
 If it needs camera, result++ and we return 1. If its covered, we return 2. Otherwise, we return 0.
 
 
 */
class Solution {
private:
    int result = 0;
    
    int dfs(TreeNode* root) {
        if(!root) return 2;
        
        int leftChild = dfs(root->left);
        int rightChild = dfs(root->right);
        
        if(leftChild == 0 || rightChild == 0) {
            result++;
            return 1;
        }
        return leftChild == 1 || rightChild == 1 ? 2 : 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1 : 0) + result;
    }
};