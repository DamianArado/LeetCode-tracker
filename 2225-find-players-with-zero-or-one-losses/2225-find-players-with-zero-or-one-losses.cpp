class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> players;
        unordered_map<int, int> losses;
        for (const auto &match : matches) {
            players.insert(match[0]);
            players.insert(match[1]);
            losses[match[1]]++;
        }
        vector<vector<int>> ans(2);
        for (const int &player : players) {
            if (!losses[player])
                ans[0].emplace_back(player);
            else if (losses[player] == 1)
                ans[1].emplace_back(player);
        }
        return ans;
    }
};