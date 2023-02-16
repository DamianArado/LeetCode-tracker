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
    unordered_map<int, vector<int>> graph; // adjacency list 
    void createGraph(TreeNode *root) {
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, -1);
        while(!q.empty()) {
            const auto [current, prev] = q.front();
            q.pop();
            if(prev != -1) {
                graph[prev].emplace_back(current->val);
                graph[current->val].emplace_back(prev);
            }
            if(current->left) q.emplace(current->left, current->val);
            if(current->right) q.emplace(current->right, current->val);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        createGraph(root);
        int time = 0;
        queue<int> q;
        q.emplace(start);
        unordered_map<int, bool> visited;
        visited[start] = true;
        while(!q.empty()) {
            int n = size(q);
            for(int i = 0; i < n; ++i) {
                int current = q.front(); 
                q.pop();
                for(const int &adjNode : graph[current]) {
                    if(!visited[adjNode]) {
                        q.emplace(adjNode);
                        visited[adjNode] = true;
                    }
                }
            }
            time++;
        }
        return time - 1;
    }
};