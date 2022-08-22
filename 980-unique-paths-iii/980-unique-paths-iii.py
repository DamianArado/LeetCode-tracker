class Solution:
    def dfs(self, grid: List[List[int]], x: int, y: int, emptyCell: int) -> int:
        # base cases -
        # 1. out of bounds and obstacles
        if x == -1 or x == len(grid) or y == -1 or y == len(grid[0]) or grid[x][y] == -1:
            return 0
        # 2. reached the ending square, check if it can be a valid 4-directional walk
        if grid[x][y] == 2:
            return emptyCell == 0
        # since it is an empty cell, we visit the current cell
        grid[x][y] = -1
        # do the 4-directional dfs walk from here
        walks = (self.dfs(grid, x + 1, y, emptyCell - 1)   # visit SOUTH 
               + self.dfs(grid, x - 1, y, emptyCell - 1)   # visit NORTH 
               + self.dfs(grid, x, y + 1, emptyCell - 1)   # visit EAST 
               + self.dfs(grid, x, y - 1, emptyCell - 1))  # visit WEST 
        # coming back we backtrack, un-visit the current cell
        grid[x][y] = 0
        return walks
    
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        emptyCell, xIdx, yIdx = 1, 0, 0
        # counting the no. of empty cells and getting the position of starting square
        # x and y coordinate of starting square are xIdx and yIdx respectively
        for i in range (len(grid)):
            for j in range (len(grid[0])):
                if grid[i][j] == 1:
                    xIdx, yIdx = i, j
                elif grid[i][j] == 0:
                    emptyCell += 1
        return self.dfs(grid, xIdx, yIdx, emptyCell)