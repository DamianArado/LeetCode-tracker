class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Set score to summation of first column
        int score = (1 << (n - 1)) * m;

        // Loop over all other columns
        for (int j = 1; j < n; j++) {
            int countSameBits = 0;
            for (int i = 0; i < m; i++) {
                // Count elements matching first in row
                if (grid[i][j] == grid[i][0]) {
                    countSameBits++;
                }
            }
            // Calculate score based on the number of same bits in a column
            countSameBits = max(countSameBits, m - countSameBits);
            // Calculate the score contribution for the current column
            int columnScore = (1 << (n - j - 1)) * countSameBits;
            // Add contribution to score
            score += columnScore;
        }

        return score;
    }
};