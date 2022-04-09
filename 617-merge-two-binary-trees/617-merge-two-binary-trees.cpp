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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // Merging trees in-place
        if(root1 && root2) { // if both nodes exist
            root1->val += root2->val; // add the combined value in root1
            root1->left = mergeTrees(root1->left, root2->left); // first recursively build the left subtree for a node
            root1->right = mergeTrees(root1->right, root2->right); // then the right subtree
        } else return root1 ? root1 : root2; // if one of them is null, append the other one to the call
        return root1; // returned the first tree as the merged tree
    }
};