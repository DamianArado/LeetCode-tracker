class Solution {
private:
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        if(i < 0 or i == m or j < 0 or j == n or board[i][j] != 'O')
            return;
        board[i][j] = '*';
        // check and mark all the adjacent Os as * and this will help us to
        // distinguish b/w which Os can be flipped
        dfs(board, i - 1, j, m, n);        
        dfs(board, i + 1, j, m, n);
        dfs(board, i, j - 1, m, n);
        dfs(board, i, j + 1, m, n);
        // the DFS stops when we can't find adjacent 'X' anymore
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        
        // We will only do DFS traversal if we found a 'O' at the boundary of matrix
        // Lets check the first and last row for a '0'
        for(int col = 0; col < n; ++col) {
            if(board[0][col] == 'O')
                dfs(board, 0, col, m, n);
            if(board[m - 1][col] == 'O')
                dfs(board, m - 1, col, m, n);
        }
        // Lets check the first and last column for a '0'
        for(int row = 0; row < m; ++row) {
            if(board[row][0] == 'O')
                dfs(board, row, 0, m, n);
            if(board[row][n - 1] == 'O')
                dfs(board, row, n - 1, m, n);
        }
        // Check and Flip all '*' -> '0' and all '0' -> X
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
};