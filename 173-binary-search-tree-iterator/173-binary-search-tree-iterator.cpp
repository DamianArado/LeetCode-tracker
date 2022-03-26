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
Store the inorder traversal inside a vector, and operate in it for next() and hasNext() functionalities
TC - O(n) SC - O(n)

Approach 2 - 
Store the current root of constructor "BSTIterator" inside a stack ADT. Now, go to its extreme left and add all the elements that you encounter. Whenever you call "next()", take out the topmost element and return its value and then 
add all the elements in its right. Whenever you call "hasNext()", check if the stack is empty or not.
TC - O(1) amortized ; SC - O(height)

*/
class BSTIterator {
private:
    stack<TreeNode*> s;
    void pushAllLeftNodes(TreeNode* node) {
        for(; node != NULL; s.push(node), node = node->left);
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAllLeftNodes(root); // add this node alongwith all the nodes to its extreme left
    }
    
    int next() {
        TreeNode* topMost = s.top();
        s.pop();
        pushAllLeftNodes(topMost->right);
        return topMost->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */