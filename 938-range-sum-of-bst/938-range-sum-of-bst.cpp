// Simple DFS traversal - O(n) TC & SC
/*class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        return (root->val >= low && root->val <= high ? root->val : 0) // check if root lies within the range
            + rangeSumBST(root->left, low, high) // recurse left
            + rangeSumBST(root->right, low, high); // recurse right
    }
};*/

// BST-optimized DFS
/*class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int ans = (root->val >= low && root->val <= high) ? root->val : 0;
        if(root->val >= low) ans += rangeSumBST(root->left, low, high);
        if(root->val <= high) ans += rangeSumBST(root->right, low, high);
        return ans;
    }
};*/

// BST-optimized BFS
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front(); q.pop();
            if(temp->val <= high && temp->val >= low) ans += temp->val;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }    
        return ans;
    }
};