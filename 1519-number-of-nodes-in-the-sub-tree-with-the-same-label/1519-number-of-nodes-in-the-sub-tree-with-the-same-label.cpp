class Solution {
private:
    void dfs(int current, int parent, vector<vector<int>> &g, string &labels, vector<int> &ans, vector<int> &count) {
        for(int &adjNode : g[current]) {
            if(adjNode != parent) {
                vector<int> counting(26);
                dfs(adjNode, current, g, labels, ans, counting);
                for(int i = 0; i < 26; ++i) 
                    count[i] += counting[i];
            }
        }
        ans[current] = ++count[labels[current] - 'a'];
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n);
        for(auto &edge : edges) {
            g[edge[0]].emplace_back(edge[1]);
            g[edge[1]].emplace_back(edge[0]);
        }
        vector<int> ans(n), count(26);
        dfs(0, -1, g, labels, ans, count);
        return ans;
    }
};