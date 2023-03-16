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
// Given an inorder and a postorder traversal of a binary tree, the binary tree that is generated from it will be unique
class Solution {
private:
    TreeNode* buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &inMappings) {
        if(inStart > inEnd || postStart > postEnd) return NULL; // base case
        TreeNode* root = new TreeNode(postorder[postEnd]); // create the root node of this tree
        int inRoot = inMappings[root->val]; // index at which the root node is present
        int numsLeft = inRoot - inStart; // number of nodes to the left of root node
        // attach the left and right subtrees using recursion
        root->left = buildTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMappings);
        root->right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMappings);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMappings; // [node.val : index]
        for(int i = 0; i < inorder.size(); ++i) inMappings[inorder[i]] = i;
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMappings);
    }
};