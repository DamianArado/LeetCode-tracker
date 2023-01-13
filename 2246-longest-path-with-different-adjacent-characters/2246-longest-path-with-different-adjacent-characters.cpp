class Solution {
private:
    int dfs(int node, vector<vector<int>> &child, string &s, int &ans) {
        int temp1 = 0, temp2 = 0;
        for(int &adjNode : child[node]) {
            int current = dfs(adjNode, child, s, ans);
            if(s[node] == s[adjNode]) continue;
            if(current > temp2) temp2 = current;
            if(temp2 > temp1) swap(temp1, temp2);
        }
        ans = max(ans, temp1 + temp2 + 1);
        return temp1 + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = size(s), ans = 0;
        vector<vector<int>> child(n);
        for(int i = 1; i < n; ++i)
            child[parent[i]].emplace_back(i);
        dfs(0, child, s, ans);
        return ans;
    }
};