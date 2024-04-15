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
    void calculateSum(TreeNode *root, int &sum, int &currentSum) {
        if (!root) return;
        if (!root->left and !root->right) {
            currentSum += root->val;
            sum += currentSum;
            return;
        }
        currentSum += root->val;
        currentSum *= 10;
        calculateSum(root->left, sum, currentSum);
        currentSum /= 10;
        currentSum *= 10;
        calculateSum(root->right, sum, currentSum);
        currentSum /= 10;
    }
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int sum = 0, currentSum = 0;
        calculateSum(root, sum, currentSum);
        return sum;
    }
};