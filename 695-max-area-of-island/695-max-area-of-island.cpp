class Solution {
private:
    int dfs(int i, int j, vector<vector<int>> &grid) {
        if(i == -1 or i == size(grid) or j == -1 or j == size(grid[0]) or grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + dfs(i - 1, j, grid) + dfs(i, j + 1, grid) + dfs(i + 1, j, grid) + dfs(i, j - 1, grid);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < size(grid); ++i) {
            for(int j = 0; j < size(grid[0]); ++j) {
                if(grid[i][j] == 1) {
                    int area = dfs(i, j, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};