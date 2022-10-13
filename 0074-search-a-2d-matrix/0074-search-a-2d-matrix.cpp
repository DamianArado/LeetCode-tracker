class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = size(matrix), col = size(matrix[0]);
        // Step 1: Search for the candidate row using binary search
        int start = 0, end = row - 1, targetRow = 0;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target and matrix[mid][col - 1] > target) {
                targetRow = mid;
                break;
            } 
            else if(matrix[mid][col - 1] < target) start = mid + 1;
            else {
                targetRow = mid;
                end = mid - 1;
            }
        }
        // Step 2: Use binary search to search for target inside this row
        start = 0, end = col - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(matrix[targetRow][mid] == target) return true;
            else if(matrix[targetRow][mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return false;
    }
};
