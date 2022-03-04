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
    // Using 1 stack - O(2*N) TC & O(N) SC
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;
        stack<TreeNode*> s;
        TreeNode *temp = root, *curr = root;
        while(curr || !s.empty()) {
            if(curr) {
                s.emplace(curr);  // add all the elements to the left
                curr = curr->left;
            } else {
                temp = s.top()->right;
                if(!temp) {
                    temp = s.top();
                    s.pop();
                    postorder.emplace_back(temp->val);
                    while(!s.empty() && temp == s.top()->right) {
                        temp = s.top();
                        s.pop();
                        postorder.emplace_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }
        return postorder;
    }
};