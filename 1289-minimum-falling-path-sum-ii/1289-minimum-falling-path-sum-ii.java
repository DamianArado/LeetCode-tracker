class Solution {
    public int minFallingPathSum(int[][] grid) {
        
        int n = grid.length, firstMin = 0, secondMin = 0, position = -1;
        if(n == 1) return grid[0][0];
        
        for(int row = 0; row < n; ++row) {
            int firstMin2 = Integer.MAX_VALUE, secondMin2 = Integer.MAX_VALUE, position2 = -1;
            
            for(int col = 0; col < n; ++col) {
                int currentMin = col != position ? firstMin : secondMin;
                
                if(grid[row][col] + currentMin < firstMin2) {
                    secondMin2 = firstMin2;
                    firstMin2 = grid[row][col] + currentMin;
                    position2 = col;
                } else 
                    secondMin2 = Math.min(secondMin2, grid[row][col] + currentMin);
            }
            firstMin = firstMin2; 
            secondMin = secondMin2;
            position = position2;
        }
        return firstMin;
    }
}