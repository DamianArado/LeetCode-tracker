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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode *current = root;
        queue<TreeNode*> q;
        q.emplace(current);
        while(!q.empty()) {
            current = q.front();
            q.pop();
            if(current->right) q.emplace(current->right);
            if(current->left) q.emplace(current->left);
        }
        return current->val;
    }
};