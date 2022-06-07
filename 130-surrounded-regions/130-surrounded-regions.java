class Solution {
    private static void dfs(char[][] board, int i, int j, int m, int n) {
        if(i < 0 || i == m || j < 0 || j == n || board[i][j] != 'O')
            return;
        board[i][j] = '*';
        dfs(board, i - 1, j, m, n);        
        dfs(board, i + 1, j, m, n);
        dfs(board, i, j - 1, m, n);
        dfs(board, i, j + 1, m, n);
    }
    
    public void solve(char[][] board) {
        int m = board.length;
        if(m == 0) return;
        int n = board[0].length;
        for(int row = 0; row < m; ++row) {
            if(board[row][0] == 'O')
                dfs(board, row, 0, m, n);
            if(board[row][n - 1] == 'O')
                dfs(board, row, n - 1, m, n);
        }
        for(int col = 0; col < n; ++col) {
            if(board[0][col] == 'O')
                dfs(board, 0, col, m, n);
            if(board[m - 1][col] == 'O')
                dfs(board, m - 1, col, m, n);
        }
        for(int row = 0; row < m; ++row) {
            for(int col = 0; col < n; ++col) {
                if(board[row][col] == 'O')
                    board[row][col] = 'X';
                if(board[row][col] == '*')
                    board[row][col] = 'O';
            }
        }
    }
}