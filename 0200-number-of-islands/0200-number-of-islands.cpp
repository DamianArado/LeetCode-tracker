// TC - O(m x n) in the worst case
class Solution {
private:
    void removeLand(vector<vector<char>>& grid, const int &i, const int &j, const int &row, const int &column) {
        // check boundary conditions
        if (i < 0 or i >= row or j < 0 or j >= column or grid[i][j] == '0') 
            return;
        // otherwise change this land to water (remove land)
        // alternative approach using extra space would involve marking visited
        grid[i][j] = '0';
        // do the same in all 4 directions (this stops until we find a point where we see 0's in all 4 directions)
        removeLand(grid, i - 1, j, row, column);
        removeLand(grid, i + 1, j, row, column);
        removeLand(grid, i, j - 1, row, column);
        removeLand(grid, i, j + 1, row, column);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // here we simply have to find the number of disconnected components (islands) in which all 1's are connected
        // we can just transform the land (1's) to water (0's) by visiting them in all 4 directions inside a cell (i,j)
        // if we don't have any land (1's) in these 4 directions, we return and thats our island 
        // as in ques, an island is formed by adjacent lands connected horizontally or vertically
        int islands = 0, row = size(grid), column = size(grid[0]);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                // check if we have a land here
                if (grid[i][j] == '1') {
                    // remove lands in all the 4 directions using DFS
                    removeLand(grid, i, j, row, column);
                    ++islands;
                }
            }
        }
        return islands;
    }
};