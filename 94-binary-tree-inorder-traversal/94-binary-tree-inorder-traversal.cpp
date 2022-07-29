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

Approach 1: Using recursion - O(n) TC & O(height) SC

class Solution {
private:
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return ans;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
};

Approach 2: Using Morris Traversal - approx. O(n) TC & O(1) SC

*/


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(!root) return inorder;
        TreeNode* current = root;
        while(current) {
            // check if there exists a left subtree to the current node
            if(current->left) {
                // use a marker for this left subtree
                TreeNode* leftSubTree = current->left;
                // keep iterating towards the rightmost node of the left subtree
                while(leftSubTree->right and leftSubTree->right != current)
                    leftSubTree = leftSubTree->right;
                // check if this node has any pre exisiting threads, if not attach one for tracking back to current node
                if(!leftSubTree->right) {
                    leftSubTree->right = current;
                    // you installed the tracker so now you can move current to its left
                    current = current->left;
                } else {
                    // there already existed a thread that means you are coming here for the second time
                    // you are moved from left subtree to the current node using this thread so remove it now
                    leftSubTree->right = nullptr;
                    // since you already visited the left subtree so now you visit the current node
                    inorder.push_back(current->val);
                    // then you move towards the right subtree
                    current = current->right;
                }
            } else {
                // its already the leftmost node of this subtree rooted at current (you're visiting the left subtree)
                inorder.push_back(current->val);
                // move current to its right to visit the right subtree (using the thread we created earlier)
                current = current->right;
            }
        }
        return inorder;
    }
};