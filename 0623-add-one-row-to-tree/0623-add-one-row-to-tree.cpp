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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) 
            return new TreeNode(val, root, NULL);
        queue<TreeNode*> bfsQ;
        bfsQ.emplace(root);
        int level = 0;
        while (!bfsQ.empty()) {
            int sizeQ = size(bfsQ);
            ++level;
            if (level == depth - 1) {
                for (int i = 0; i < sizeQ; ++i) {
                    TreeNode *current = bfsQ.front();
                    bfsQ.pop();
                    TreeNode *leftSubtree = new TreeNode(val, current->left, NULL);
                    TreeNode *rightSubtree = new TreeNode(val, NULL, current->right);
                    current->left = leftSubtree;
                    current->right = rightSubtree;
                }
                return root;
            } else {
                for (int i = 0; i < sizeQ; ++i) {
                    TreeNode *current = bfsQ.front();
                    bfsQ.pop();
                    if (current->left) bfsQ.emplace(current->left);
                    if (current->right) bfsQ.emplace(current->right);
                }
            }
        }
        return root;
    }
};