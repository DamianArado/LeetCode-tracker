class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = size(grid), col = size(grid[0]), total = 0, count = 0, minutes = 0;
        const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        queue<pair<int, int>> rotten;
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) rotten.emplace(i, j);
            }
        }
        
        while(!rotten.empty()) {
            int sz = size(rotten);
            count += sz;
            for(int i = 0; i < sz; ++i) {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i) {
                    int dxi = x + dx[i], dxj = y + dy[i];
                    if(dxi == -1 or dxi == row or dxj == -1 or dxj == col or grid[dxi][dxj] != 1)
                        continue;
                    grid[dxi][dxj] = 2;
                    rotten.emplace(dxi, dxj);
                }
            }
            if(!rotten.empty()) minutes++;
        }
        
        return count == total ? minutes : -1;
    }
};