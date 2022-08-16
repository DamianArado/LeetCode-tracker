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
    int calculate(TreeNode* root, int& maxSum) {
        // sum of the null node is always 0
        if(!root) return 0;
        // calculate the left and right path sum for the current node
        // if the path sum is -ve, you'll not consider that part at all
        int leftPathSum = max(0, calculate(root->left, maxSum));
        int rightPathSum = max(0, calculate(root->right, maxSum));
        // do the calculations to update the maxSum for the current node
        maxSum = max(maxSum, root->val + leftPathSum + rightPathSum);
        // return the max path calculation so that we can update the maxSum variable for the current node
        return root->val + max(leftPathSum, rightPathSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        calculate(root, maxSum);
        // returning this since it has the max path sum stored in it
        return maxSum;
    }
};