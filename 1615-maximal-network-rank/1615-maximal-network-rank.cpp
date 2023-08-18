class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> inDegrees(n);
        vector<vector<bool>> connected(n, vector<bool> (n));
        for (const auto &road : roads) {
            ++inDegrees[road[0]], ++inDegrees[road[1]];
            connected[road[0]][road[1]] = connected[road[1]][road[0]] = true;
        }
        int maxNetworkRank = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                maxNetworkRank = max(maxNetworkRank, (
                    inDegrees[i] + inDegrees[j] - (connected[i][j] == true ? 1 : 0)));
        return maxNetworkRank;
    }
};