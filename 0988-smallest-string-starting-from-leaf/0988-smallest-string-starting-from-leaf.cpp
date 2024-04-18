class Solution {
private:
    void dfs(TreeNode* node, string path, string &smallest) {
        if (node == NULL) return;
        
        // Append current node's character to the path
        path += char('a' + node->val);
        
        // If it's a leaf node, compare and update smallest
        if (node->left == NULL and node->right == NULL) {
            reverse(path.begin(), path.end());
            if (smallest.empty() or path < smallest) 
                smallest = path;
            reverse(path.begin(), path.end()); // backtrack by reversing again
        }
        
        // Recursively traverse left and right subtrees
        dfs(node->left, path, smallest);
        dfs(node->right, path, smallest);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string smallest, path;
        dfs(root, path, smallest);
        return smallest;
    }
};