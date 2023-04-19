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
    void zigzagPath(TreeNode *root, int leftPath, int rightPath, int &ans) {
        if(root == NULL) return;
        ans = max(ans, max(leftPath, rightPath));
        zigzagPath(root->left, 0, leftPath + 1, ans);
        zigzagPath(root->right, rightPath + 1, 0, ans);
    }
public:
    int longestZigZag(TreeNode* root) {
        int leftPath = 0, rightPath = 0, ans = 0;
        zigzagPath(root, leftPath, rightPath, ans);
        return ans;
    }
};