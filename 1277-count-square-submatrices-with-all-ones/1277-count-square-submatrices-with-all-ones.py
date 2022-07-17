class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        row = len(matrix)
        col = len(matrix[0])
        
        dp = [[0] * col for _ in range(row)]
        
        for i in range (0, row):
            dp[i][0] = matrix[i][0]
        for j in range (0, col):
            dp[0][j] = matrix[0][j]
            
        for i in range (1, row):
            for j in range (1, col):
                if matrix[i][j] == 0:
                    dp[i][j] = 0
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]))
        
        sum = 0
        for i in range (0, row):
            for j in range (0, col):
                sum += dp[i][j]
        return sum