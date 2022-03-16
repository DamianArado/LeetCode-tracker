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
Calculate left and right height if they are equal, 2^h - 1 is the ans
Otherwise go a step below to find the left and right height again
Much better than O(n) TC as its O(logn)
SC is also O(h) and for a complete Binary Tree, h = log^2N
*/
class Solution {
private:
    int findLeftHeight(TreeNode* node) {
        int height = 0;
        while(node) {
            height++;
            node = node->left;
        }
        return height;
    }
    
    int findRightHeight(TreeNode* node) {
        int height = 0;
        while(node) {
            height++;
            node = node->right;
        }
        return height;
    }
    
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if(lh == rh) return (1 << lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};