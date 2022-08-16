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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> levelOrder;
        if(!root) return levelOrder;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            double sum = 0, avg = 0;
            for(int i = 0; i < n; ++i) {
                TreeNode* current = q.front();
                q.pop();
                sum += current->val;
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            avg = sum / n;
            sum = 0;
            levelOrder.push_back(avg);
        }
        return levelOrder;
    }
};