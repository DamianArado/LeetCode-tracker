class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # Start from the top-right corner
        row, col = 0, len(matrix[0]) - 1

        # Keeps searching when there are unclassified rows and columns
        while row < len(matrix) and col >= 0:
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] < target:
                # Eliminate this row
                row += 1
            else:
                # Greater than target, elimimate this column
                col -= 1
        return False