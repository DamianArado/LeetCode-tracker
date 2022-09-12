class Solution {
private:
    void dfs(vector<vector<int>> &grid, int i, int j) {
        if(i == -1 or i == size(grid) or j == -1 or j == size(grid[0]) or grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // use flood fill to mark all the cells that are set to 1 in grid2 and connected to 0-celled grid1
        for(int i = 0; i < size(grid1); ++i) {
            for(int j = 0; j < size(grid1[0]); ++j) {
                if(grid1[i][j] == 0) 
                    dfs(grid2, i, j);
            }
        }
        // only the common cells remain now and the number of islands hence will be our sub islands
        int subIslands = 0;
        for(int i = 0; i < size(grid1); ++i) {
            for(int j = 0; j < size(grid1[0]); ++j) {
                if(grid2[i][j] == 1) {
                    subIslands++;
                    dfs(grid2, i, j);
                }
            }
        }
        return subIslands;
    }
};