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
    void checkPath(TreeNode* root, int sum, int targetSum, vector<int> &path, vector<vector<int>> &ans) {
        if(!root) return;
        
        path.emplace_back(root->val);
        sum += root->val;
        
        if(sum == targetSum and !root->left and !root->right) {
            ans.emplace_back(path);
            path.pop_back();
            sum -= root->val;
            return;
        }
        
        checkPath(root->left, sum, targetSum, path, ans);
        checkPath(root->right, sum, targetSum, path, ans);
        
        path.pop_back();
        sum -= root->val;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        checkPath(root, 0, targetSum, path, ans);
        return ans;
    }
};