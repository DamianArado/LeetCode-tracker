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
private:
    int calculate(TreeNode* node, int &maxPSum) {
        if(!node) return 0;
        int leftSum = max(0, calculate(node->left, maxPSum)); // don't take negative path sum, instead take 0 in case of negative path sum
        int rightSum = max(0, calculate(node->right, maxPSum));
        maxPSum = max(maxPSum, leftSum + rightSum + node->val); // store the max path sum among all the nodes
        return node->val + max(leftSum, rightSum); // to decide which path to take among the left and right as the longest path (maximum path sum from the current node)
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPSum = INT_MIN;
        calculate(root, maxPSum);
        return maxPSum;
    }
};