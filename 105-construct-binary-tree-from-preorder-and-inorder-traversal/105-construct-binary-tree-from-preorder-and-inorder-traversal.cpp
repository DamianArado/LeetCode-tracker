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

If an inorder and preorder traversal is given, then the binary tree which we create will be unique.

1. Hash all the values of inorder as they are guaranteed to be unique
2. Take the 1st guy from preorder and then find it in inorder and label it x (say)
3. Take all the elements before x in inorder and add it to the left subtree of x
4. Take all the elements after x in order and add it to the right subtree of x
5. In preorder, it will be like -> [x, ...left...., ...right...]
   In inorder, it will be like -> [...left..., x, ...right...]

*/
class Solution {
private:
    TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, 
                       int inEnd, map<int, int> &inMappings) {
        if(preStart > preEnd || inStart > inEnd) return NULL; // base case
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inMappings[root->val];
        int numsLeft = inRoot - inStart; // ...left...
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMappings);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMappings);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMappings;
        for(int i = 0; i < inorder.size(); ++i) inMappings[inorder[i]] = i; // hashing inorder values
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMappings);
    }
};