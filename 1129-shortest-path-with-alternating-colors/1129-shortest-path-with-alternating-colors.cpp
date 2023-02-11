class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
       
       for(auto &it : redEdges){
         adj[it[0]].push_back({it[1],0});
       }
       
       for(auto &it : blueEdges){
         adj[it[0]].push_back({it[1],1});
       }
       
       vector<int> ans(n,-1);
       vector<vector<bool>> visited(n, vector<bool>(2));
       queue<vector<int>> q; 
       
       q.push({0,0,-1}); // node, step, color
       visited[0][0]=true;
       visited[0][1]=true;
       ans[0]=0;
       
       while(!q.empty()){
         vector<int> curr=q.front(); q.pop();
         int node=curr[0],step=curr[1],prevcolor=curr[2];
         
         for(auto [nbr,color]: adj[node]){
           if(!visited[nbr][color]==true && color!=prevcolor){
             visited[nbr][color]=true;
             q.push({nbr,1+step,color});  
             if(ans[nbr]==-1){
             ans[nbr]=1+step;
             }       
           }         
         }    
       }
       return ans; 
    }
};