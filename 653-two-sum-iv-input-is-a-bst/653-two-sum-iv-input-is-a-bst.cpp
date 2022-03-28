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

Approach 1 - O(N) TC & O(N) SC
We'll do an inorder and save the result inside a vector, which will be sorted and then to check for the 2 sum
We could have easily used the 2 pointers strategy.

Approach 2 - O(N) TC & 2*O(H) SC
We'll use the BST iterator class to iterate over the inorder of the BST

*/

class BSTIterator {
  private:
    stack<TreeNode*> s;
    bool reverse = true;
    
    void pushAll(TreeNode* node) {
        for(; node != NULL;) {
            s.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }
    
  public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        if(reverse) pushAll(temp->left);
        else pushAll(temp->right);
        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next(), j = r.next(); // inorder, reverse inorder
        while(i < j) { // simulating 2 pointers in bst
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};