class Solution {
public:
    /**
    
    We are maintaining the answer in firstMin, here we will consider min 
    to be firstMin if its not in the same column
    as the previous firstMin, otherwise we'll consider min to be secondMin.
    firstMin2, secondMin2 and pos2 are just here during the current iteration (column)
    and they help us in updating firstMin, secondMin and position for the next column
    
    TC: O(n^2), SC: O(1)
    
    */
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), firstMin = 0, secondMin = 0, position = -1;
        if(n == 1) return grid[0][0];
        for(int row = 0; row < n; ++row) {
            int firstMin2 = INT_MAX, secondMin2 = INT_MAX, position2 = -1;
            for(int col = 0; col < n; ++col) {
                int currentMin = position != col ? firstMin : secondMin;
                if(grid[row][col] + currentMin < firstMin2) {
                    secondMin2 = firstMin2;
                    firstMin2 = grid[row][col] + currentMin;
                    position2 = col;
                } else secondMin2 = min(secondMin2, grid[row][col] + currentMin);
            }
            firstMin = firstMin2, secondMin = secondMin2, position = position2;
        }
        return firstMin;
    }
};