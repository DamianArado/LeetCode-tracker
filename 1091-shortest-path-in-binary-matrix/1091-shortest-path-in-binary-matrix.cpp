class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>> qu;
        vector<vector<bool>> visit(r,vector(c,false));
        
        if(grid[0][0] == 1 || grid[r-1][c-1] == 1){
            return -1;
        }
        
        qu.push(make_pair(0,0));
        visit[0][0] = true;
        
        while(!qu.empty()){
            int steps = qu.size();
            ans++;
            
            /*directions*/
            for(int i = 0;i < steps; ++i){
                int x = qu.front().first;
                int y = qu.front().second;
                qu.pop();
                if(x == r-1 && y == c-1){
                    return ans;
                }
                
                for(int j = 0;j < 8; ++j){
                    int x1 = x + d[j][0];
                    int y1 = y + d[j][1];
                    if(x1 >= 0 && x1 < r && y1 >= 0 && y1 < c){
                        if(!visit[x1][y1] && !grid[x1][y1]){
                            qu.push(make_pair(x1,y1));
                            visit[x1][y1] = true;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};