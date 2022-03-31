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
// TC - O(n) SC - O(n)
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root) return result;
        stack<TreeNode*> s; // for doing level-order traversal
        stack<string> path; // for storing the individual paths
        s.push(root);
        path.push(to_string(root->val));
        
        while(!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            string currentPath = path.top(); // current path while going level-order wise
            path.pop();
            
            if(!current->left && !current->right) { // leaf node, add the computed path to result
                result.emplace_back(currentPath);
                continue;
            }
            
            if(current->left) {   // add the path towards the left
                s.push(current->left);
                path.push(currentPath + "->" + to_string(current->left->val));
            }
            if(current->right) {    // add the path towards the right
                s.push(current->right);
                path.push(currentPath + "->" + to_string(current->right->val));
            }
        }
        return result;
    }
};