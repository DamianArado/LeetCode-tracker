class Solution {
private:
    bool dfs(int i, int j, int row, int col, int &count, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        if(i == -1 or i == row or j == -1 or j == col) return false;
        if(grid[i][j] == 0 or visited[i][j]) return true;
        visited[i][j] = true;
        ++count;
        bool up = dfs(i - 1, j, row, col, count, grid, visited);
        bool down = dfs(i + 1, j, row, col, count, grid, visited);
        bool left = dfs(i, j - 1, row, col, count, grid, visited);
        bool right = dfs(i, j + 1, row, col, count, grid, visited);
        return up and down and left and right;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = size(grid), col = size(grid[0]), enclaves = 0;
        vector<vector<bool>> visited(row, vector<bool> (col));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                int count = 0;
                if(!visited[i][j] and grid[i][j] == 1 and dfs(i, j, row, col, count, grid, visited))
                    enclaves += count;
            }
        }
        return enclaves;
    }
};