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
    int helper(TreeNode* root, int &gdNodes, int maxTillNow) {
        if(!root) return gdNodes;
        if(root->val >= maxTillNow) {
            maxTillNow = root->val;
            gdNodes++;
        }
        helper(root->left, gdNodes, maxTillNow);
        helper(root->right, gdNodes, maxTillNow);
        return gdNodes;
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int gdNodes = 0, maxTillNow = INT_MIN;
        return helper(root, gdNodes, maxTillNow);
    }
};