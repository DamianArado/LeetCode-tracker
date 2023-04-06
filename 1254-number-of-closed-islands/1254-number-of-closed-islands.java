class Solution {
    private boolean dfs(int i, int j, int row, int col, boolean[][] visited, int[][] grid) {
        if(i == -1 || i == row || j == -1 || j == col) return false;
        if(grid[i][j] == 1 || visited[i][j]) return true;
        visited[i][j] = true;
        boolean up = dfs(i - 1, j, row, col, visited, grid);
        boolean down = dfs(i + 1, j, row, col, visited, grid);
        boolean left = dfs(i, j - 1, row, col, visited, grid);
        boolean right = dfs(i, j + 1, row, col, visited, grid);
        return up && down && left && right;

    }
    public int closedIsland(int[][] grid) {
        int row = grid.length, col = grid[0].length, islands = 0;
        boolean[][] visited = new boolean[row][col];
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == 0 && !visited[i][j] && dfs(i, j, row, col, visited, grid))
                    ++islands;
            }
        }
        return islands;
    }
}