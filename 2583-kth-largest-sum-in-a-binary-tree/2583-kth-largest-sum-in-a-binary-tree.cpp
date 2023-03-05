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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> maxHeap;
        queue<TreeNode*> q;
        q.push(root);
        int levels = 0;
        while(!q.empty()) {
            int n = size(q);
            long long currentSum = 0;
            for(int i = 0; i < n; ++i) {
                int current = q.front()->val;
                currentSum += current;
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);                
                q.pop();
            }
            maxHeap.push(-currentSum);
            ++levels;
            if(size(maxHeap) > k) maxHeap.pop();
        }
        if(levels < k) return -1;
        if(maxHeap.empty()) return -1;
        return -maxHeap.top();
    }
};