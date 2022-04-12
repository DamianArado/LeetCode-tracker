class Solution {
public:
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
};