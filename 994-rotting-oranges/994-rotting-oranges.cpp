class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int oranges = 0;  // no. of valid cells (cells with orange)
        int result = -1;  // no. of minutes to rot all the oranges
        queue<pair<int,int>> q; // to store rotten oranges
        vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // increase the count of oranges
                if(grid[i][j] > 0) 
                    oranges++;
                // add only the cells having rotten oranges
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        
        // start BFS
        while(!q.empty()) {
            result++;  // increase the no. of minutes for rotting oranges
            int qSize = q.size();
            for(int k = 0; k < qSize; ++k) {
                auto it = q.front();
                q.pop();
                oranges--;  // decrease the no. of orange as it is rotten

                // check for rotten oranges in all the 4 directions
                for(int i = 0; i < 4; ++i) {
                    int x = it.first + directions[i][0];
                    int y = it.second + directions[i][1];
                    // skip if both go beyond the current limits
                    if(x == m || y == n || x < 0 || y < 0 || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    q.push({x,y});  // add this rotten one to queue
                }
            }
        }
        
        // since all oranges have been rotten now, return the result
        return (oranges == 0) ? max(0, result) : -1;
    }
};