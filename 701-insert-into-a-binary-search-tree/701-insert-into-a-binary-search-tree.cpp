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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* current = root;
        while(true) {
            if(current->val <= val) {   // it'll be on the right side
                if(current->right) current = current->right;
                else {   // no more nodes on the right side, so we attach it here
                    current->right = new TreeNode(val);
                    break;
                }
            } else {    // it'll be on the left side
                if(current->left) current = current->left;
                else {   // no more nodes on the left side, so we attach it here
                    current->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};