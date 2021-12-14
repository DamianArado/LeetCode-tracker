class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // Start from the top-right corner
        int row = 0, col = matrix[0].size() - 1;

        // Keeps searching when there are unclassified rows and columns
        while(row<matrix.size() && col >= 0) {
            if(matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {

                // Eliminate this row
                ++row;
            } else {

                // A[row][col] > target, eliminate this column
                --col;
            }
        }
        return false;
    }
};