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
    int maxLevelSum(TreeNode* root) {
        int maxSumLevel = INT_MIN, levelCount = 0, level = 0;
        if(!root->left && !root->right) return root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int sum = 0;
            for(int i = 0; i < n; i++) {
                TreeNode* current = q.front();
                q.pop();
                sum += current->val;
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            levelCount++;
            if(sum > maxSumLevel) {
                maxSumLevel = sum;
                level = levelCount;
            }
        }
        return level;
    }
};