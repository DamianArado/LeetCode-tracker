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
    int maxAncestorDiff(TreeNode* root, int minNode = 1e9, int maxNode = 0) {
        if(root == NULL) return maxNode - minNode;
        minNode = min(minNode, root->val), maxNode = max(maxNode, root->val);
        return max(maxAncestorDiff(root->left, minNode, maxNode), 
                   maxAncestorDiff(root->right, minNode, maxNode));
    }
};