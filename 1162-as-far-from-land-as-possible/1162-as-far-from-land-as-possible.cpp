class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = size(grid);
        // idea is the same as 01 Matrix
        // here we need to find the distance of each land cell from the water cell
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) continue;
                int top = 1e9, left = 1e9;
                if(i > 0) top = grid[i - 1][j];
                if(j > 0) left = grid[i][j - 1];
                grid[i][j] = 1 + min(top, left);
            }
        }
        for(int i = n - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                int bottom = 1e9, right = 1e9;
                if(i < n - 1) bottom = grid[i + 1][j];
                if(j < n - 1) right = grid[i][j + 1];
                grid[i][j] = min(grid[i][j], 1 + min(bottom, right));
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                ans = max(ans, grid[i][j]);
            }
        }
        return ans - 1 == 1e9 + 1 or ans - 1 == 0 ? -1 : ans - 1;
    }
};