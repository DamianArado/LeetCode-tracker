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
    int min_dif = INT_MAX, val = -1;    
    
    int getMinimumDifference(TreeNode* root) {
        
        if(root->left) getMinimumDifference(root->left);
        
        if(val >= 0) min_dif = min(min_dif, root->val - val);
        
        val = root->val;
        
        if(root->right) getMinimumDifference(root->right);
        
        return min_dif;
    }
};