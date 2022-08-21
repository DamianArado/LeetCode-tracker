class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(), col = dungeon[0].size();
        // hp: minimum health points required at an index (i, j) 
        vector<vector<int>> hp(row + 1, vector<int> (col + 1, INT_MAX));
        // since you would reach the end, so you will have min 1 extra health point
        hp[row][col - 1] = hp[row - 1][col] = 1;
        // construct the DP table
        for(int i = row - 1; i >= 0; --i) {
            for(int j = col - 1; j >= 0; --j) {
                // calculate the current need with the help of the event happening in the future
                // you want to take the minimum hp path in the future 
                // current hp = -dungeon[i][j] + min hp path
                int minHP = - dungeon[i][j] + min(hp[i][j + 1], hp[i + 1][j]);
                // if negative that simply means you have more than sufficient hp here
                hp[i][j] = minHP <= 0 ? 1 : minHP;
            }
        }
        return hp[0][0];
    }
};