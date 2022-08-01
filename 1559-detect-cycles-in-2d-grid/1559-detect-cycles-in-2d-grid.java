class Solution {
    // prevMove: 0 - start of DFS, 1 - up, 2 - right, 3 - down, 4 - left
    private static boolean isCycle2DGrid(char[][] grid, 
                                         int prevMove, int i, int j, char c, boolean[][] visited) {
        if((i == -1 || i == grid.length) || (j == -1 || j == grid[0].length) || grid[i][j] != c)
            return false;
        if(visited[i][j]) return true;
        
        visited[i][j] = true;
        return (prevMove != 1 && isCycle2DGrid(grid, 3, i + 1, j, grid[i][j], visited))
            || (prevMove != 2 && isCycle2DGrid(grid, 4, i, j - 1, grid[i][j], visited))
            || (prevMove != 3 && isCycle2DGrid(grid, 1, i - 1, j, grid[i][j], visited))
            || (prevMove != 4 && isCycle2DGrid(grid, 2, i, j + 1, grid[i][j], visited));
    }
    public boolean containsCycle(char[][] grid) {
        int row = grid.length, col = grid[0].length;
        boolean[][] visited = new boolean[row][col];
        
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                if(!visited[i][j])
                    if(isCycle2DGrid(grid, 0, i, j, grid[i][j], visited))
                        return true;
        
        return false;
    }
}