/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* findLastRight(TreeNode* root) {
        while(root->right) root = root->right;  // find the rightmost child to root's left
        return root;
    }
    
    TreeNode* changeConnections(TreeNode* root) {
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        
        // connect the rightmost (largest val) node of of left of root -> to the right of root
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        
        return root->left; // root->left would be placed instead of root
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key) return changeConnections(root);
        TreeNode* newRoot = root;
        
        while(root) {
            if(key < root->val) {
                if(root->left && root->left->val == key) {
                    root->left = changeConnections(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if(root->right && root->right->val == key) {
                    root->right = changeConnections(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        
        return newRoot;  // since we modified root
    }
};