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
For every node go and check the best place to attach it. 
TC - O(n^2) SC - O(1)

Approach 2 - 
Sort the preorder and then you'll get the inorder. Then, using both inorder and preorder you can
create a unique Binary Tree. 
TC - O(nlogn) SC - O(n)

Approach 3 -


*/
class Solution {
private:
    TreeNode* build(vector<int> &preorder, int &i, int bound) {
        // if we reach the last node || if the current element is greater than the upper bound
        if(i == preorder.size() || preorder[i] > bound) return NULL;
        // otherwise we create a node
        TreeNode* node = new TreeNode(preorder[i++]);
        // now we first attach a node to the left with upper bound as the current node
        node->left = build(preorder, i, node->val);
        // then we attach a node to the right with its upper bound equal to node's upper bound
        node->right = build(preorder, i, bound);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0; // starting index of preorder
        return build(preorder, i, INT_MAX);
    }
};