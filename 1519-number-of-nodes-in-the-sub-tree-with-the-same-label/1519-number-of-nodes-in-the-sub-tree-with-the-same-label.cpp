class Solution {
public:
    vector<int> ans;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        for(auto &i:edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans.resize(n,0);
        vector<int> count(26,0);
        dfs(0,-1,count,adj,labels);
        return ans;
    }
    void dfs(int node,int parent,vector<int>& count,vector<int> adj[],string &labels){
        for(auto &i:adj[node]){
            if(i!=parent){
                vector<int> counting(26,0);
                dfs(i,node,counting,adj,labels);
                for(int i=0;i<26;i++){
                    count[i]=count[i]+counting[i];
                }
            }
        }
        count[labels[node]-'a']++;
        ans[node]=count[labels[node]-'a'];
    }
};