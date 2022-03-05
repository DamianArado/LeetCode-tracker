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
    // Morris Traversal - O(n) TC & O(1) SC
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(!root) return preorder;
        TreeNode *curr = root;
        while(curr) {
            if(!curr->left) {  // if there is nothing on left it's the leftmost
                preorder.emplace_back(curr->val);  // print the current root
                curr = curr->right;  // move right from here
            } else {  // we have something on left
                TreeNode *prev = curr->left;  // use prev as marker for the left subtree analysis
                while(prev->right && prev->right != curr) prev = prev->right; // till we reach the rightmost node of that left subtree
                if(!prev->right) {  // we reached the rightmost node of the left subtree
                    preorder.emplace_back(curr->val);  // print the current root
                    prev->right = curr;  // create the thread that joins the rightmost element to the current root
                    curr = curr->left;  // now move towards left from here
                } else {  // if the thread already exists
                    prev->right = NULL;  // cut the thread that exists
                    curr = curr->right;  // now move right from here
                }
            }
        }
        return preorder;
    }
};