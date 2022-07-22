class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        
        # Step 1: Find the row in which target can lie (the last element which is smaller than target in the 1st column)
        start, end, targetRow = 0, m - 1, 0
        while start <= end:
            mid = start + (end - start) // 2
            if target == matrix[mid][0]: 
                return True
            if target > matrix[mid][0]:
                targetRow = mid
                start = mid + 1
            else:
                end = mid - 1
                
        # Step 2: Search in this row using binary search
        start, end = 0, n - 1
        while start <= end:
            mid = start + (end - start) // 2
            if target == matrix[targetRow][mid]:
                return True
            if target > matrix[targetRow][mid]:
                start = mid + 1
            else:
                end = mid - 1
        
        # If element is not present in the matrix
        return False