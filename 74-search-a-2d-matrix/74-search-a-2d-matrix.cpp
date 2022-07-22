/**

Approach 1: Using steps - O(m + n) TC & O(1) SC

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

Approach 2: Using Binary Search - O(log m + log n) or O(log mn) TC & O(1) SC
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        // Step 1: Find the row in which target can lie (the last element which is smaller than target in the 1st column)
        int start = 0, end = m - 1, targetRow = 0;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(target == matrix[mid][0]) return true;
            if(target > matrix[mid][0]) {
                targetRow = mid;
                start = mid + 1;
            } else end = mid - 1;
        }
        
        // Step 2: Search in this row using binary search
        start = 0, end = n - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(target == matrix[targetRow][mid]) return true;
            if(target > matrix[targetRow][mid]) start = mid + 1;
            else end = mid - 1;
        }
        // If element is not present in the matrix
        return false;
    }
};