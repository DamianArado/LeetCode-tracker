class Solution {
private:
    bool dfs(int i, int j, int row, int col, vector<vector<int>>& grid, vector<vector<bool>> &visited) {
        if(i == -1 or i == row or j == -1 or j == col) return false;
        if(grid[i][j] == 1 or visited[i][j]) return true;
        visited[i][j] = true;
        bool up = dfs(i - 1, j, row, col, grid, visited);
        bool down = dfs(i + 1, j, row, col, grid, visited);
        bool left = dfs(i, j - 1, row, col, grid, visited);
        bool right = dfs(i, j + 1, row, col, grid, visited);
        return up and down and left and right;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row = size(grid), col = size(grid[0]);
        vector<vector<bool>> visited(row, vector<bool>(col));
        int islands = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == 0 and !visited[i][j] and dfs(i, j, row, col, grid, visited))
                    ++islands;
            }
        }
        return islands;
    }
};