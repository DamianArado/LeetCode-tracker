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
    int dfsHelper(TreeNode* root, int &goodNodes, int maxTillNow) {
        if(!root) return goodNodes;
        if(root->val >= maxTillNow) {
            maxTillNow = root->val;
            goodNodes++;
        }
        dfsHelper(root->left, goodNodes, maxTillNow);
        dfsHelper(root->right, goodNodes, maxTillNow);
        return goodNodes;
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int goodGuys = 0;
        return dfsHelper(root, goodGuys, INT_MIN);
    }
};