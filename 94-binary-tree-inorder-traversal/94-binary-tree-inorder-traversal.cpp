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
// Morris Traversal - O(n) time and O(1) space
/*

Approach - 

Starting the inorder traversal, we know that we have to go to the left node first. Before moving to the
left of the current node, check whether the left exists or not and if it does not exist that means you are 
at the root of the current subtree, so print it and move towards the right.

If the left of current node exists, before going towards left mark the current node's left as `prev` and then
go towards the rightmost node of `prev`. Then, check whether its null or not. If its null take the right 
pointer of this and point it to the current node (so that you can return back to the root of the current node's
subtree from the left). 

If its not null, mark it to null and go to the current node and print it.Since, you came back to the root of 
the current subtree, and you have already printed it, you can move towards the right and continue the inorder traversal.

*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(!root) return inorder;
        TreeNode *current = root;
        while(current) {
            if(!current->left) {
                inorder.emplace_back(current->val);
                current = current->right;
            } else {
                TreeNode* prev = current->left;
                while(prev->right && prev->right != current) prev = prev->right;
                if(!prev->right) {
                    prev->right = current;
                    current = current->left;
                } else {
                    prev->right = NULL;
                    inorder.emplace_back(current->val);
                    current = current->right;
                }
            }
        }
        return inorder;
    }
};