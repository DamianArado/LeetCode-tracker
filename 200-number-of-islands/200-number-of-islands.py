class Solution:
    def removeLand(self, grid: List[List[str]], i: int, j: int) -> None:
        if i == -1 or i == len(grid) or j == -1 or j == len(grid[0])  or grid[i][j] == '0':
            return
        grid[i][j] = '0'
        self.removeLand(grid, i - 1, j)
        self.removeLand(grid, i, j + 1)
        self.removeLand(grid, i + 1, j)
        self.removeLand(grid, i, j - 1)
        
    def numIslands(self, grid: List[List[str]]) -> int:
        islands = 0
        for i in range (len(grid)):
            for j in range (len(grid[0])):
                if grid[i][j] == '1':
                    self.removeLand(grid, i, j)
                    islands += 1
        return islands