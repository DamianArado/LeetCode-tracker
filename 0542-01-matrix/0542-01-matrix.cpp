class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Using DP here is a 2-step process
        int rows = size(mat), cols = size(mat[0]);
        // Step1: Compute shortest distances from top-left to bottom-right
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) continue;
                int top = 1e9, left = 1e9;
                if (i > 0) top = mat[i - 1][j];
                if (j > 0) left = mat[i][j - 1];
                mat[i][j] = 1 + min(top, left);
            }
        }
        // Step2: Compute shortest distances from bottom-right to top-left
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j >= 0; --j) {
                int bottom = 1e9, right = 1e9;
                if (i < rows - 1) bottom = mat[i + 1][j];
                if (j < cols - 1) right = mat[i][j + 1];
                mat[i][j] = min(mat[i][j], 1 + min(bottom, right));
            }
        }
        // using these 2 steps we are sure of considering the shortest distance to 0
        // in all the four directions
        return mat;
    }
};