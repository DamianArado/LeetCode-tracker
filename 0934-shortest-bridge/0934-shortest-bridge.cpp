/**

This one requires heck load of bug-free code!

The DFS + BFS approach goes like this - 

Step 1: Find the first island using DFS and mark all the cells inside it as '-1'. After it's done, you can 
easily distinguish b/w 1st and the 2nd island (which is marked as '1')

Step 2: For the first island insert all its nodes inside the BFS queue and move outside in a layer-wise
fashion

Step 3: While moving outside as soon as you see a cell marked as '1' return the answer.

I call this approach as the shortest distance between 2 independent set of contiguous cells using 
multi-source BFS.

TC: O(n^2)
SC: O(n^2)

*/

class Solution {
private:
    void dfs(int i, int j, vector<vector<int>> &grid) {
        if(i == -1 or i == size(grid) or j == -1 or j == size(grid[0]) or grid[i][j] != 1)
            return;
        grid[i][j] = -1;
        dfs(i - 1, j, grid), dfs(i + 1, j, grid);
        dfs(i, j - 1, grid), dfs(i, j + 1, grid);
    }
    bool isValid(int i, int j, int row, int col, vector<vector<int>> &grid) {
        if(i == -1 or i == row or j == -1 or j == col or grid[i][j] == -1)
            return false;
        grid[i][j] == 0 ? grid[i][j] = -1 : grid[i][j] = 1;
        return true;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int row = size(grid), col = size(grid[0]);
        bool isIsland = false;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == 1) {
                    dfs(i, j, grid);
                    isIsland = true;
                    break;
                }
            }
            if(isIsland) break;
        }
        queue<vector<int>> q;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == -1)
                    q.push({i, j, 0});
            }
        }
        while(!q.empty()) {
            for(int k = 0; k < size(q); ++k) {
                auto it = q.front();
                q.pop();
                int i = it[0], j = it[1], flips = it[2];
                if(grid[i][j] == 1) 
                    return flips - 1;
                if(isValid(i - 1, j, row, col, grid))
                    q.push({i - 1, j, flips + 1});
                if(isValid(i + 1, j, row, col, grid))
                    q.push({i + 1, j, flips + 1});
                if(isValid(i, j - 1, row, col, grid))
                    q.push({i, j - 1, flips + 1});
                if(isValid(i, j + 1, row, col, grid))
                    q.push({i, j + 1, flips + 1});
            }
        }
        return 0;
    }
};