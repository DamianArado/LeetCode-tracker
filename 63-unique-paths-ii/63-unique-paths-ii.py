class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        prevRow = [0] * (n)
        for i in range (m):
            curRow = [0] * (n)
            for j in range (n):
                if obstacleGrid[i][j] == 1:
                    curRow[j] = 0
                    continue
                if i == 0 and j == 0: 
                    curRow[0] = 1
                    continue
                down, right = 0, 0
                if j > 0: right = curRow[j - 1]
                if i > 0: down = prevRow[j]
                curRow[j] = right + down 
            prevRow = curRow
        return prevRow[n - 1]