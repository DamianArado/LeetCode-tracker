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
    int findDeepestLevel(TreeNode* root) {
        return root == nullptr ? 0 : 1 + max(findDeepestLevel(root->left), findDeepestLevel(root->right));
    }
    
    int deepestLeavesSum(TreeNode* root, int &deepestLevel, int currentLevel) {
        if(!root) return 0;
        if(!root->left and !root->right) 
            return deepestLevel == currentLevel ? root->val : 0;
        return deepestLeavesSum(root->left, deepestLevel, currentLevel + 1) 
            + deepestLeavesSum(root->right, deepestLevel, currentLevel + 1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int deepestLevel = findDeepestLevel(root) - 1;
        return deepestLeavesSum(root, deepestLevel, 0);
    }
};