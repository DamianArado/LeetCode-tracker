/*

Approach 1 - O(n^2) TC & O(n) SC

TreeNode* buildTree(vector<int> &pre, vector<int> &post, int &preindex, int start, int end) {
        if(start > end) return NULL;
        TreeNode* new_head = new TreeNode(pre[preindex++]);
        if(preindex == pre.size()) return new_head;
        int i = start;
        for(; i <= end; i++) {
            if(pre[preindex] == post[i])
                break;
        }
        if(i <= end) {
            new_head->left = buildTree(pre, post, preindex, start, i);
            new_head->right = buildTree(pre, post, preindex, i + 1, end - 1);
        }
        return new_head;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.size() == 1) return new TreeNode(pre[0]);
        int preIdx = 0;
        return buildTree(pre, post, preIdx, 0, pre.size() - 1);
    }

*/

class Solution {
public:
    // TC & SC - O(n)
    int preIdx = 0, postIdx = 0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[preIdx++]);
        if (root->val != post[postIdx])
            root->left = constructFromPrePost(pre, post);
        if (root->val != post[postIdx])
            root->right = constructFromPrePost(pre, post);
        postIdx++;
        return root;
    }
};