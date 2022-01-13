class Solution {
private:
    bool isPalindrome(string &s, int i, int j) {
        while(i <= j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void solve(int idx, string &s, vector<string> &path, vector<vector<string>> &res) {
        if(idx == s.size()) {
            res.emplace_back(path);
            return;
        }
        for(int i = idx; i < s.size(); ++i) {
            if(isPalindrome(s, idx, i)) {
                path.emplace_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> res;
        solve(0, s, path, res);
        return res;
    }
};