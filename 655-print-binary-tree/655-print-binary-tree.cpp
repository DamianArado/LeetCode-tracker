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
    int maxDepth(TreeNode* node){
        if(!node) return -1;
        
        int leftDepth = -1;
        if(node->left) 
            leftDepth = maxDepth(node->left);
        
        int rightDepth = -1;
        if(node->right)
            rightDepth = maxDepth(node->right);
        
        return 1 + max(leftDepth, rightDepth);
    }
    
    void fillTable(TreeNode* node, int depth, int start, int end, vector<vector<string>>& table){
        if(!node) return;
        
        int mid = start + (end - start) / 2;
        table[depth][mid] = to_string(node->val);
        
        if(node->left)
            fillTable(node->left,  depth + 1, start, mid - 1, table);
        if(node->right)
            fillTable(node->right, depth + 1, mid + 1, end, table);
    }
public:
    vector<vector<string>> printTree(TreeNode* root){
        
        vector<vector<string>> res;
        
        //
        // create table of empty strings ""
        // based on the tree height/width
        //
        int depth = maxDepth(root);
        int width = pow(2, depth + 1) - 1;
        vector<string> row (width, "");
        for (int i = 0; i <= depth; i++){
            res.push_back(row);
        }
        
        //
        // traverse the tree and fill in table values for non-NULL nodes
        //
        fillTable(root, 0, 0, width - 1, res);
        return res;
    }
};