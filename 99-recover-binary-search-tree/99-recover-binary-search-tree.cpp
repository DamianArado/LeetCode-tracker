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
/*

Approach 1 -
Go through the changed bst using inorder and then sort it to generate the correct inorder. After this, compare values
at each index and correct those 2 values.

TC - O(nlogn) SC - O(n)

Approach 2 -
Just do a single inorder traversal and maintain 4 pointers: first, middle, last and prev.
prev: the previous node with respect to the current
first: the first node that is taking part in the violation (its value > its next's value)
middle: the second node that is taking part in the violation if there is no last node (adjacent to first)
last: the second node that is taking part in the violation (not adjacent to first)

If there exists only first and last, swap them. Otherwise, there will be first and middle only so swap these 2.
After this the bst will be recovered.

TC - O(n) SC - O(n) recursive stack & O(1) morris traversal

*/
class Solution {
private:
    TreeNode *first, *middle, *last, *prev;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        
        // this is where our core logic of the problem resides
        if(prev && prev->val > root->val) {
            if(!first) {   // if we have the 1st violation
                first = prev;
                middle = root;  // maintaining this just in case both the nodes are adjacent to each other
            } else last = root; // 2nd violation if both are not adjacent
        }
        // mark the current root as prev
        prev = root;
        
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        first = middle = last = NULL;
        TreeNode* prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};