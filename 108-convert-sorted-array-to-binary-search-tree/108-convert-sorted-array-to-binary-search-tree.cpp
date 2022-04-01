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
    TreeNode* helper(vector<int> &nums, int lowerLimit, int higherLimit) {
        if(lowerLimit <= higherLimit) {
            int mid = lowerLimit + (higherLimit - lowerLimit) / 2;
            return new TreeNode(nums[mid], helper(nums, lowerLimit, mid - 1), helper(nums, mid + 1, higherLimit));
        }
        return NULL;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};