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
// O(n) TC & SC
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
      vector<vector<int>> result;
      if (!root) return result;

      queue<TreeNode *> q;
      q.emplace(root);
      while (!q.empty()) {
          int n = q.size();
          vector<int> crtLevel;
          // insert elements level by level
          for (int i = 0; i < n; i++) {
              TreeNode *p = q.front();
              q.pop();
              crtLevel.emplace_back(p->val);
              if (p->left) q.emplace(p->left);
              if (p->right) q.emplace(p->right);
          }
          result.emplace_back(crtLevel);
      }
      return result;
    }
};