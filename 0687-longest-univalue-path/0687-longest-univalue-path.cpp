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
    int longest = 0;
    
    int traverse(TreeNode* root, int parentVal) {
        if(root == nullptr) return 0;
        int left = traverse(root->left, root->val);
        int right = traverse(root->right, root->val);
        longest = max(longest, left + right);
        
        if(root->val == parentVal) return 1 + max(left, right);
        return 0;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        traverse(root, -1);
        return longest;
    }
};