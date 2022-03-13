/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
    The brute-force approach involves finding paths for both p and q and then checking what are the common nodes along
    those paths and the last common one would be the lowest common ancestor.
    TC -> O(n) SC -> O(n) + extra space to store path
*/
/*
    Now, in our space optimzed aprroach, we are using DFS traversal and we'll go to each node and return it's value if we get both it's left and right child returned not as NULL. 
    Actually, we're checking if it is one of the nodes p and q that we're looking for. 
    The path which has p or q returns its value. The node which gets p from one side returned and q on the other side
    is the Lowest Common Ancestor. After that, it returns its value too above and going on finally, the root node 
    gets returned LCA on one side and NULL on the other side and it takes LCA and returns it as the answer.
    TC -> O(n) SC -> O(n)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base-case
        if(!root || root == p || root == q) return root;
        // Left and Right DFS Traversal
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // if we got null from left return right
        if(left == NULL) return right;
        // if we got null from right return left
        else if(right == NULL) return left;
        // if we don't get null from both sides we are on the node which is the answer LCA node hence we return it from here
        else return root;
    }
};