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
    bool isLeaf(TreeNode* root) {
        return !root->left and !root->right;
    }
    void checkPath(TreeNode* root, int sum, int targetSum, vector<int> &current, vector<vector<int>> &ans) {
        if(!root) return;
        
        current.emplace_back(root->val);
        sum += root->val;
        
        if(sum == targetSum and isLeaf(root)) {
            ans.emplace_back(current);
            current.pop_back();
            sum -= root->val;
            return;
        }
        checkPath(root->left, sum, targetSum, current, ans);
        checkPath(root->right, sum, targetSum, current, ans);
        
        current.pop_back();
        sum -= root->val;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> current;
        checkPath(root, 0, targetSum, current, ans);
        return ans;
    }
};