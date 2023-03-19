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
    TreeNode *buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart,
                       int postEnd, unordered_map<int, int> &inMappings) {
        if(inStart > inEnd or postStart > postEnd) return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inorderRoot = inMappings[root->val];
        int numTowardsLeft = inorderRoot - inStart;
        root->left = buildTree(inorder, inStart, inorderRoot - 1, postorder, 
                               postStart, postStart + numTowardsLeft - 1, inMappings);
        root->right = buildTree(inorder, inorderRoot + 1, inEnd, 
                                postorder, postStart + numTowardsLeft, postEnd - 1, inMappings);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n1 = size(inorder), n2 = size(postorder);
        unordered_map<int, int> inMappings;
        for(int i = 0; i < n1; ++i)
            inMappings[inorder[i]] = i;  // help us to track in inorder 
        return buildTree(inorder, 0, n1 - 1, postorder, 0, n2 - 1, inMappings);
    }
};