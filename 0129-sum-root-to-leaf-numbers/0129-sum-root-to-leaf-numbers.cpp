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
// MORE VERBOSE FOR SHITHEAD LIKE ME!
// class Solution {
// private:
//     void calculateSum(TreeNode *root, int &sum, int &currentSum) {
//         if (!root) return;
//         if (!root->left and !root->right) {
//             currentSum += root->val;
//             sum += currentSum;
//             return;
//         }
//         currentSum += root->val;
//         currentSum *= 10;
//         calculateSum(root->left, sum, currentSum);
//         currentSum /= 10;
//         currentSum *= 10;
//         calculateSum(root->right, sum, currentSum);
//         currentSum /= 10;
//     }
// public:
//     int sumNumbers(TreeNode* root) {
//         if (!root) return 0;
//         int sum = 0, currentSum = 0;
//         calculateSum(root, sum, currentSum);
//         return sum;
//     }
// };
class Solution {
private:
    int sumNumbers(TreeNode *root, int sum) {
        if (root == NULL) return 0;
        if (root->left == NULL and root->right == NULL) 
            return sum * 10 + root->val;
        return sumNumbers(root->left, sum * 10 + root->val) + sumNumbers(root->right, sum * 10 + root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
};