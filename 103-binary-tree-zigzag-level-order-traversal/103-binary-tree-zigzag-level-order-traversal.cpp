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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigZag;
        if(!root) return zigZag;
        
        bool leftToRight = true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> level(n);
            
            for(int i = 0; i < n; ++i) {
                TreeNode* current = q.front();
                q.pop();
                
                // find the position to insert the node
                int idx = leftToRight ? i : n - i - 1;
                level[idx] = current->val;
                
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            
            leftToRight = !leftToRight;
            zigZag.emplace_back(level);
        }
        
        return zigZag;
    }
};