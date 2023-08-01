class Solution {
private:
    void backtrack (int &n, int &k, vector<vector<int>> &ans, vector<int> &current, int i) {
        if (size(current) == k) 
            ans.emplace_back(current);
        else {
            for (int j = i; j <= n; ++j) {
                current.emplace_back(j);
                backtrack(n, k, ans, current, j + 1);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(n, k, ans, current, 1);
        return ans;
    }
};