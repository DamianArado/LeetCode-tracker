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
    string serialize(TreeNode *root, unordered_map<string, vector<TreeNode*>> &map) {
        if(root == NULL) return "x";
        string s = to_string(root->val) + "," + serialize(root->left, map) + "," + serialize(root->right, map);
        map[s].emplace_back(root);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplicates;
        unordered_map<string, vector<TreeNode*>> map;
        serialize(root, map);
        for(const auto &it : map) 
            if(it.second.size() > 1)
                duplicates.emplace_back(it.second[0]);
        return duplicates;
    }
};