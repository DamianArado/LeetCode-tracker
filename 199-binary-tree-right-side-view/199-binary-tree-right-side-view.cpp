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
    void recursion(TreeNode* root, int level, vector<int> &result) {
        if(!root) return;
        if(level == result.size()) result.emplace_back(root->val);
        // Reverse Preorder traversal: Root -> Right -> Left for printing the right side of binary tree
        // To print the left side of binary tree, do Preorder
        recursion(root->right, level + 1, result);
        recursion(root->left, level + 1, result);
    }
public:
    // TC -> O(n) SC -> O(height)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        recursion(root, 0, result);
        return result;
    }
};