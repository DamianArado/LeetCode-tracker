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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if(!root) return rightView;
        
        queue<TreeNode*> q;
        q.emplace(root);
        
        while(!q.empty()) {
            int n = q.size();
            int value = 0;
            for(int i = 0; i < n; ++i) {
                TreeNode *current = q.front();
                q.pop();
                if(current->left) q.emplace(current->left);
                if(current->right) q.emplace(current->right);
                if(i == n - 1) value = current->val;
            }
            rightView.emplace_back(value);
        }
        
        return rightView;
    }
};