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
    int sumNumbers(TreeNode *root, int sum) {
        if(root == NULL) return 0;
        if(root->left == NULL and root->right == NULL) 
            return sum * 10 + root->val;
        return sumNumbers(root->left, sum * 10 + root->val) + sumNumbers(root->right, sum * 10 + root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
};