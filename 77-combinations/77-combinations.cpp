class Solution {
private:
    void backtrack(vector<vector<int>>&ans, vector<int>&curr, int n, int k, int index) {
        if(curr.size() == k) {
            ans.emplace_back(curr);
            return;
        } else { 
            for(int i = index; i <= n; ++i) {
                curr.emplace_back(i);
                backtrack(ans, curr, n, k, i + 1);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, n, k, 1);
        return ans;
    }
};