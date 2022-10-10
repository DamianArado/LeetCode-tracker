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
    int sumRootToLeaf(TreeNode* root, int sum = 0) {
        if(root == nullptr) return 0;
        sum = sum * 2 + root->val;
        return root->left == root->right ? 
            sum : sumRootToLeaf(root->left, sum) + sumRootToLeaf(root->right, sum);
    }
};