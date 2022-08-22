class Solution {
    private int dfs(int[][] grid, int x, int y, int emptyCell) {
        // base cases -
        // 1. out of bounds and obstacles
        if(x == -1 || x == grid.length || y == -1 || y == grid[0].length || grid[x][y] == -1)
            return 0;
        // 2. reached the ending square, check if it can be a valid 4-directional walk
        if(grid[x][y] == 2)
            return emptyCell == 0 ? 1 : 0;
        // since it is an empty cell, we visit the current cell
        grid[x][y] = -1;
        // do the 4-directional dfs walk from here
        int walks = 
              dfs(grid, x + 1, y, emptyCell - 1)   // visit SOUTH
            + dfs(grid, x - 1, y, emptyCell - 1)   // visit NORTH
            + dfs(grid, x, y + 1, emptyCell - 1)   // visit EAST
            + dfs(grid, x, y - 1, emptyCell - 1);  // visit WEST
        // coming back we backtrack, un-visit the current cell
        grid[x][y] = 0;
        return walks;
    }
    public int uniquePathsIII(int[][] grid) {
        int emptyCell = 1, xIdx = 0, yIdx = 0;
        // counting the no. of empty cells and getting the position of starting square
        // x and y coordinate of starting square are xIdx and yIdx respectively
        for(int i = 0; i < grid.length; ++i) {
            for(int j = 0; j < grid[0].length; ++j) {
                if(grid[i][j] == 1) {
                    xIdx = i;
                    yIdx = j;
                } else if(grid[i][j] == 0) {
                    ++emptyCell;
                }
            }
        }
        return dfs(grid, xIdx, yIdx, emptyCell);
    }
}