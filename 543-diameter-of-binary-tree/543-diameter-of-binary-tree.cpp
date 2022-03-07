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
/*

Naive solution - O(n^2) TC & O(n) SC

For each of the N nodes, find leftHeight + rightHeight and take the max of it.

diameterOfBinaryTree(root) {
    if(!root) return;
    leftHeight = diameterOfBinaryTree(root->left);  // at max O(n) [Skewed Trees]
    rightHeight = diameterOfBinaryTree(root->right);
    diameter = max(leftHeight + rightHeight);
    diameterOfBinaryTree(root->left);  // at max O(n) [left skewed trees]
    diameterOfBinaryTree(root->right);
    return diameter;
}

*/
class Solution {
private:
    int calculate(TreeNode* root, int &diameter) {
        if(!root) return 0;
        int leftHeight = calculate(root->left, diameter);
        int rightHeight = calculate(root->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculate(root, diameter);
        return diameter;
    }
};