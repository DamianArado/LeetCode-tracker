class Solution {
private:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, 
    vector<bool> &leftRow, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal, int n) {
        // check if we reached the last column
        if(col == n) {
            // add to current board of queens
            ans.emplace_back(board);
            return;
        }
        // for each row check if we can place a queen or not
        for(int row = 0; row < n; ++row) {
            /*
             * leftRow = all the rows to the left of the cell([row][col])
             * lowerDiagonal = all the cells to the bottom left of the cell([row][col])
             * upperDiagonal = all the cells to the top right of the cell([row][col])
             *
             */
            if(leftRow[row] == false && lowerDiagonal[row + col] == false 
               && upperDiagonal[n - 1 + col - row] == false) {
                    // if no queen at these positions we place one
                    board[row][col] = 'Q';
                    leftRow[row] = true;
                    lowerDiagonal[row + col] = true;
                    upperDiagonal[n - 1 + col - row] = true;
                    solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                    // backtracking
                    board[row][col] = '.';
                    leftRow[row] = false;
                    lowerDiagonal[row + col] = false;
                    upperDiagonal[n - 1 + col - row] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; ++i) board[i] = s;
        // auxilary space required for storing whether a queen is present or not
        vector<bool> leftRow(n, false), upperDiagonal(2*n - 1, false), lowerDiagonal(2*n - 1, false);
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};