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
// TC -> O(n) SC -> O(n) [Height due to recursion in case of skewed trees] ; n = no. of nodes
class Solution {
private:
    vector<int> ans;
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return ans;
        // Root -> Left -> Right
        ans.emplace_back(root->val);  
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};