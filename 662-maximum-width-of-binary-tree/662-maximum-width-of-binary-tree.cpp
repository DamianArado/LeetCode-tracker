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
    long widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long ans = 0;
        queue<pair<TreeNode*, long>> q; // [Node, Index]
        q.push({root, 0});
        while(!q.empty()) {
            long first, last;
            long size = q.size();
            long curr_level_min = q.front().second; // take the minimum of each level (the leftmost index)
            for(long i = 0; i < size; ++i) {
                long curr_id = q.front().second - curr_level_min; // to prevent overflow in case of skewed trees
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = curr_id;
                if(i == size - 1) last = curr_id;
                if(node->left) q.push({node->left, 2 * curr_id + 1}); // left child's index
                if(node->right) q.push({node->right, 2 * curr_id + 2}); // right child's index
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};