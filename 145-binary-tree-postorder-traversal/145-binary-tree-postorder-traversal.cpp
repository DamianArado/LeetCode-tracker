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


/**

Approach 1 - O(n) Tc & O(height) SC

class Solution {
private:
    vector<int> postorder;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return postorder;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        postorder.push_back(root->val);
        return postorder;
    }
};

Approach 2 - Morris traversal

*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;
        TreeNode* current = root;
        while(current) {
            if(current->right) {
                TreeNode* rightSubTree = current->right;
                while(rightSubTree->left and rightSubTree->left != current)
                    rightSubTree = rightSubTree->left;
                if(!rightSubTree->left) {
                    postorder.push_back(current->val);
                    rightSubTree->left = current;
                    current = current->right;
                } else {
                    rightSubTree->left = nullptr;
                    current = current->left;
                }
            } else {
                postorder.push_back(current->val);
                current = current->left;
            }
        }
        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
};