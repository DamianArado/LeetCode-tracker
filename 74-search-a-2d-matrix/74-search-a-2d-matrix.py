class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        row, col = 0, 0
        while row < m and col < n:
            if target == matrix[row][col]: return True
            if target > matrix[row][n - 1]: row += 1
            else: col += 1
        return False