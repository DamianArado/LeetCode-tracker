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
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* current = st.top();
            st.pop();
            
            if(current->right) st.push(current->right);
            if(current->left) st.push(current->left);
            
            if(!st.empty()) current->right = st.top();
            
            current->left = NULL;
        }
    }
};