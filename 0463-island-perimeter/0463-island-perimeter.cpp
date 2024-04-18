class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = size(grid), col = size(grid[0]), perimeter = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                perimeter += 4 * grid[i][j];
                if (i > 0) 
                    perimeter -= grid[i][j] * grid[i - 1][j];
                if (i < row - 1) 
                    perimeter -= grid[i][j] * grid[i + 1][j];
                if (j > 0) 
                    perimeter -= grid[i][j] * grid[i][j - 1];
                if (j < col - 1) 
                    perimeter -= grid[i][j] * grid[i][j + 1];
            }
        }
        return perimeter;
    }
};