class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(begin(score), end(score), [&] (auto x, auto y) { return x[k] > y[k]; });
        return score;
    }
};                                                        