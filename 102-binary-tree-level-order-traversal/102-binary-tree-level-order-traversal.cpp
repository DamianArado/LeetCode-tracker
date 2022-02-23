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
    vector<vector<int>> levelOrder(TreeNode *root) {
      vector<vector<int>> result;
      if (!root) return result;

      queue<TreeNode *> q;
      q.push(root);
      while (!q.empty()) {
          int n = q.size();
          vector<int> crtLevel;
          for (int i = 0; i < n; i++) {
              TreeNode *p = q.front();
              q.pop();
              crtLevel.push_back(p->val);
              if (p->left) q.push(p->left);
              if (p->right) q.push(p->right);
          }
          result.push_back(crtLevel);
      }
      return result;
    }
};