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
    int inorder(TreeNode *root, int &parent, int &minDiff) {
        if(root->left) inorder(root->left, parent, minDiff);
        if(parent != -1) minDiff = min(minDiff, root->val - parent);
        parent = root->val;
        if(root->right) inorder(root->right, parent, minDiff);
        return minDiff;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX, parent = -1;
        return inorder(root, parent, minDiff);
    }
};