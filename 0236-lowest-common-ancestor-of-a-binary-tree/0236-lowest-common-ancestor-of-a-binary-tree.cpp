/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Code for finding ancestor of target in a binary tree
// TreeNode *findAncestor(TreeNode* root, int target) {
//     if(root == NULL) return NULL;
//     if((root->left != NULL and root->left->val == target) or (root->right != NULL and root->right->val == target)) return root;
//     TreeNode *left = findAncestor(root->left, target);
//     TreeNode *right = findAncestor(root->right, target);
//     return left != NULL ? left : right;
// }
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL or root == p or root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return left != NULL and right != NULL ? root : (left != NULL ? left : right);
    }
};