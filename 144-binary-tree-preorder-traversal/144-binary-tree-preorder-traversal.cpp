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
    // TC & SC -> O(n) 
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        // Root -> Left -> Right
        s.emplace(root);
        while(!s.empty()) {
            TreeNode *temp = s.top();
            s.pop();
            ans.emplace_back(temp->val);
            if(temp->right) s.emplace(temp->right);
            if(temp->left) s.emplace(temp->left);
        }
        return ans;
    }
};