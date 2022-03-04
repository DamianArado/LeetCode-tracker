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
    // Using 2 stacks
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;
        stack<TreeNode*> s1, s2;
        s1.emplace(root);  // initial config
        while(!s1.empty()) { 
            root = s1.top();  // take the first element of stack 1
            s1.pop();
            s2.emplace(root);  // insert in stack 2
            if(root->left) s1.emplace(root->left);  // insert left and right of that element
            if(root->right) s1.emplace(root->right);  // in stack 1
        }
        while(!s2.empty()) {  // postorder == LIFO of stack 2
            postorder.emplace_back(s2.top()->val);
            s2.pop();
        }
        return postorder;
    }
};