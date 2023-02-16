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
    int findDepth(TreeNode *root) {
        if(root == nullptr) return INT_MAX;
        if(root->left == nullptr and root->right == nullptr) return 1;
        return 1 + min(findDepth(root->left), findDepth(root->right));
    }
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return findDepth(root);
    }
};