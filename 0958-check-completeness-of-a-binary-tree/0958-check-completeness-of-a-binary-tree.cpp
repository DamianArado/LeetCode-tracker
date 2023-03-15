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
    bool isCompleteTree(TreeNode* root) {
        int counter = 1;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);
        while(!q.empty()) {
            auto [node, number] = q.front();
            q.pop();
            if(number != counter) return false;
            if(node->left != NULL) q.emplace(node->left, 2 * number);
            if(node->right != NULL) q.emplace(node->right, 2 * number + 1);
            ++counter;
        }
        return true;
    }
};