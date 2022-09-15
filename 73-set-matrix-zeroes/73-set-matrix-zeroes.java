class Solution {
    public void setZeroes(int[][] matrix) {
        boolean isZeroRow = false, isZeroCol = false;
        
        // check for the first row and the first column whether they have zeroes or not
        for(int i = 0; i < matrix.length; ++i) {
            if(matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            }
        }
        for(int j = 0; j < matrix[0].length; ++j) {
            if(matrix[0][j] == 0) {
                isZeroRow = true;
                break;
            }
        }
        
        // check for the remaining elements and if anyone is zero, install your markers
        // which would be the first element in that row or column
        for(int i = 1; i < matrix.length; ++i) {
            for(int j = 1; j < matrix[0].length; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // using the markers set above mark the entire row or column zero
        for(int i = 1; i < matrix.length; ++i) {
            for(int j = 1; j < matrix[0].length; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        // process the first row or column incase they have zero entries as well
        if(isZeroRow)
            for(int j = 0; j < matrix[0].length; ++j)
                matrix[0][j] = 0;
        if(isZeroCol)
            for(int i = 0; i < matrix.length; ++i)
                matrix[i][0] = 0;
    }
}