class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
      vector<vector<int>> knows(N + 1, vector<int>(N + 1));
      for (auto &t : trust) knows[t[0]][t[1]] = 1;
      return findCelebrity(N, knows);
    }
    int findCelebrity(int n, vector<vector<int>>& knows, int i = 1) {
      for (auto j = i + 1; j <= n; ++j) if (knows[i][j]) i = j;
      for (auto j = 1; j < i; ++j) if (knows[i][j]) return -1;
      for (auto j = 1; j <= n; ++j) if (i != j && !knows[j][i]) return -1;
      return i;
    }
};