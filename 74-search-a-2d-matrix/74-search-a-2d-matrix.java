class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int row = 0, col = 0;
        while(row < m && col < n) {
            if(target == matrix[row][col]) return true;
            if(target > matrix[row][n - 1]) row++;
            else col++;
        }
        return false;
    }
}