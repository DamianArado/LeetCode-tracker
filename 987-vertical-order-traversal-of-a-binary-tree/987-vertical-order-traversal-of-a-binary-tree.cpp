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
// TC -> O(N) [for going at each node] * O(log N) [for using multiset to keep values sorted]
// SC -> O(N) [for using map and queue]
// explanation: https://youtu.be/q_a6lpbKJdw?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // map<vertical, map<level, multinodes>>
        queue<pair<TreeNode*, pair<int, int>>> todo; // queue<TreeNode, pair<vertical, level>>
        todo.push({root, {0, 0}});
        while(!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode *node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left) todo.push({node->left, {x - 1, y + 1}}); // left child     
            if(node->right) todo.push({node->right, {x + 1, y + 1}}); // right child
        }
        vector<vector<int>> ans;
        for(auto p : nodes) {
            vector<int> col;
            for(auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end()); // insert in sorted fashiom
            }
            ans.emplace_back(col);
        }
        return ans;
    }
};