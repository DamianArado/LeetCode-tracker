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

We have 2 possible ways to solve this: Recursive and Iterative

The Recursive approach takes O(n) recursive stack space in case of Skewed Binary Tree
The Iterative approach takes O(n) space in worst case in case of complete Binary Tree

Taking the recursive approach, we break the solution into the recurrence: 1 + max(left, right)

*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return 1 + max(maxLeft, maxRight);
    }
};