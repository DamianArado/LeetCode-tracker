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
    // max length between the left and right elements on any level in a binary tree
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        double width = 0;
        queue<pair<TreeNode*, double>> q;
        q.emplace(root, 0);
        while(!q.empty()) {
            double start = q.front().second, end = q.back().second, n = q.size();
            width = max(width, end - start + 1);
            for(int i = 0; i < n; ++i) {
                auto current = q.front();
                double idx = current.second - start;
                q.pop();
                // checking for children
                if(current.first->left != nullptr)
                    q.emplace(current.first->left, 2 * idx + 1);
                if(current.first->right != nullptr) 
                    q.emplace(current.first->right, 2 * idx + 2);
            }
        }
        return (int)width;
    }
};