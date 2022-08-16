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
    int dfs(TreeNode* root, bool isLeft) {
        if(!root) return 0;
        if(!root->left and !root->right) 
            return isLeft == true ? root->val : 0;
        return dfs(root->left, true) + dfs(root->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};