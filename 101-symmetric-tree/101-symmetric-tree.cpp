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
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if(left == NULL || right == NULL) return left == right;
        if(left->val != right->val) return false;
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
public:
    // TC -> O(n) SC -> O(n)
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetricHelper(root->left, root->right);
    }
};