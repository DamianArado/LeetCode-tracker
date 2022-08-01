class Solution {
private:
    // param: move - all 4 moves (0 - start dfs, 1 - up, 2 - right, 3 - down, 4 - left)
    bool isCycleDFS(vector<vector<char>> &grid, int prevMove, int i, int j, 
                    char &c, vector<vector<bool>> &visited) {
        if((i == -1 or i == grid.size()) or (j == -1 or j == grid[0].size()) or grid[i][j] != c)
            return false;
        if(visited[i][j]) return true;
        visited[i][j] = true;
        
        return (prevMove != 1 and isCycleDFS(grid, 3, i + 1, j, grid[i][j], visited))
            or (prevMove != 2 and isCycleDFS(grid, 4, i, j - 1, grid[i][j], visited))
            or (prevMove != 3 and isCycleDFS(grid, 1, i - 1, j, grid[i][j], visited))
            or (prevMove != 4 and isCycleDFS(grid, 2, i, j + 1, grid[i][j], visited));
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool> (col, false));
        
        for(int i = 0; i < row; ++i) 
            for(int j = 0; j < col; ++j) 
                if(!visited[i][j])
                    if(isCycleDFS(grid, 0, i, j, grid[i][j], visited))
                        return true;
        
        return false;
    }
};