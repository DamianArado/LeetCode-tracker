class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = 0;
        while(row < m and col < n) {
            if(target == matrix[row][col]) return true;
            if(target > matrix[row][n - 1]) row++;
            else col++;
        }
        return false;
    }
};