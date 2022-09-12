class Solution {
    private int dfs(int i, int j, int[][] grid) {
        if(i == -1 || i == grid.length || j == -1 || j == grid[0].length || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + dfs(i - 1, j, grid) + dfs(i, j + 1, grid) + dfs(i + 1, j, grid) + dfs(i, j - 1, grid);
    }
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.length; ++i) {
            for(int j = 0; j < grid[0].length; ++j) {
                if(grid[i][j] == 1) {
                    int area = dfs(i, j, grid);
                    maxArea = Math.max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
}