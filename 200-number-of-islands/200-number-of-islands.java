class Solution {
    void removeLand(char[][] grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        removeLand(grid, i - 1, j);
        removeLand(grid, i + 1, j);
        removeLand(grid, i, j - 1);
        removeLand(grid, i, j + 1);
    }
    public int numIslands(char[][] grid) {
        int islands = 0;
        for(int i = 0; i < grid.length; ++i) {
            for(int j = 0; j < grid[0].length; ++j) {
                if(grid[i][j] == '1') {
                    removeLand(grid, i, j);
                    ++islands;
                }
            }
        }
        return islands;
    }
}