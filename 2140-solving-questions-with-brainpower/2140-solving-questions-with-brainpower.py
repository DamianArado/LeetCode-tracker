class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        dp = [0] * n
        dp[n - 1] = questions[n - 1][0];
        for idx in range (n - 2, -1, -1):
            point, bpower = questions[idx][0], questions[idx][1];
            solve, skip = questions[idx][0], dp[idx + 1];
            if idx + bpower + 1 < n: solve += dp[idx + bpower + 1];
            dp[idx] = max(solve, skip);
        return dp[0];