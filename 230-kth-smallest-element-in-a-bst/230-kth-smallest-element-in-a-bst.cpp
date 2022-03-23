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
public:
    int kthSmallest(TreeNode* root, int k) {
        // Inorder Morris Traversal: whenever you visit the root node, decrease k and when k == 0, return the current node
        int kthSmallest;
        TreeNode* current = root;
        while(current) {
            if(!current->left) {
                k -= 1;
                if(k == 0) kthSmallest = current->val;
                current = current->right;
            } else {
                TreeNode* prev = current->left;
                while(prev->right && prev->right != current) prev = prev->right;
                
                if(!prev->right) {
                    prev->right = current;
                    current = current->left;
                } else {
                    prev->right = NULL;
                    k -= 1;
                    if(k == 0) kthSmallest = current->val;
                    current = current->right;
                }
            }
        }
        return kthSmallest;
    }
};