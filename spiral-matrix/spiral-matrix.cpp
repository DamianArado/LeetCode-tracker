/*
Traverse the matrix in the spiral order by keeping four variables: 
startRow for the uppermost row, endRow for the downmost row, startCol for the leftmost column and endCol for the rightmost column.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int numRows = matrix.size(), numCols = numRows ? matrix[0].size() : 0;
        int startRow = 0, endRow = numRows - 1, startCol = 0, endCol = numCols - 1, k = 0;
        
        vector<int> order(numRows * numCols);
        
        while(startRow <= endRow && startCol <= endCol) {
            
            // Elements of startRow enter the array
            for(int col = startCol; col <= endCol; col++) {
                order[k++] = matrix[startRow][col];
            }
            startRow++;
            
            // Elements of endCol enter the array
            for(int row = startRow; row <= endRow; row++) {
                order[k++] = matrix[row][endCol];
            }
            endCol--;
            
            if(endRow >= startRow) {
                // Elements of endRow enter the array
                for(int col = endCol; col >= startCol; col--) {
                    order[k++] = matrix[endRow][col];
                }
                endRow--;
            }
            
            if(endCol >= startCol) {
                // Elements of startCol enter the array
                for (int row = endRow; row >= startRow; row--) {
                    order[k++] = matrix[row][startCol];
                }
                startCol++;
            }
        }
        return order;
    }
};