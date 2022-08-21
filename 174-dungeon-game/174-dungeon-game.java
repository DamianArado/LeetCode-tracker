class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int row = dungeon.length, col = dungeon[0].length;
        int[][] hp = new int[row + 1][col + 1];
        for(int[] row_elem : hp)
            Arrays.fill(row_elem, Integer.MAX_VALUE);
        hp[row][col - 1] = hp[row - 1][col] = 1;
        
        for(int i = row - 1; i >= 0; --i) {
            for(int j = col - 1; j >= 0; --j) {
                int minHP = -dungeon[i][j] + Math.min(hp[i][j + 1], hp[i + 1][j]);
                hp[i][j] = minHP <= 0 ? 1 : minHP;
            }
        }
        
        return hp[0][0];
    }
}