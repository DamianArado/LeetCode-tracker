class Solution {
private:
    bool isPalindrome(string &s, int i, int j) {
        while(i < j) 
            if(s[i++] != s[j--]) 
                return false;
        return true;
    }
    void solve(int index, string &s, vector<string> &partitions, vector<vector<string>> &palindromes) {
        if(index == size(s)) {
            palindromes.emplace_back(partitions);
            return;
        }
        for(int i = index; i < size(s); ++i) {
            if(isPalindrome(s, index, i)) {
                partitions.emplace_back(s.substr(index, i - index + 1));
                solve(i + 1, s, partitions, palindromes);
                partitions.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        vector<vector<string>> palindromes;
        solve(0, s, partitions, palindromes);
        return palindromes;
    }
};