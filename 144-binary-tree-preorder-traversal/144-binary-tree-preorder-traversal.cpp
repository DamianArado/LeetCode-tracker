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

Approach 1 - O(n) TC & O(height) SC

class Solution {
private:
    vector<int> preorder;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return preorder;
        preorder.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return preorder;
    }
};

Approach 2 - approx. O(n) TC & O(1) SC [Morris]

*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(!root) return preorder;
        TreeNode* current = root;
        while(current) {
            if(current->left) {
                TreeNode* leftSubTree = current->left;
                while(leftSubTree->right and leftSubTree->right != current)
                    leftSubTree = leftSubTree->right;
                if(!leftSubTree->right) {
                    leftSubTree->right = current;
                    preorder.push_back(current->val);
                    current = current->left;
                } else {
                    leftSubTree->right = nullptr;
                    current = current->right;
                }
            } else {
                preorder.push_back(current->val);
                current = current->right;
            }
        }
        return preorder;
    }
};