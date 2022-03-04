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
    // Iterative version - O(n) TC & SC
    vector<int> inorderTraversal(TreeNode* root) {
        stack <TreeNode*> s;
        vector <int> inorder;
        TreeNode *node = root;
        while (1) {
            if (node) {
                s.emplace(node);
                node = node->left;
            } else {
                if (s.empty()) break;
                node = s.top();
                s.pop();
                inorder.emplace_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};