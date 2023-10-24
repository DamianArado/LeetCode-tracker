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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) 
            return ans;
        queue<TreeNode*> bfs;
        bfs.emplace(root);
        while (!bfs.empty()) {
            int largest = INT_MIN, n = size(bfs);
            for (int i = 0; i < n; ++i) {
                TreeNode *current = bfs.front();
                bfs.pop();
                largest = max(largest, current->val);
                if (current->left)
                    bfs.emplace(current->left);
                if (current->right)
                    bfs.emplace(current->right);
            }
            ans.emplace_back(largest); 
        }
        return ans;
    }
};