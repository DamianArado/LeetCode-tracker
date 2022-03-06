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

In a balanced binary tree, for every node the left and right subtree's heights should not differ by more
than 1.

*/
class Solution {
private:
    // Calculate the height of the binary tree in O(n)
    int dfsHeight(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = dfsHeight(root->left);
        int maxRight = dfsHeight(root->right);
        if(abs(maxLeft - maxRight) > 1) return -1;
        if(maxLeft == -1 || maxRight == -1) return -1;
        return 1 + max(maxLeft, maxRight);
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};