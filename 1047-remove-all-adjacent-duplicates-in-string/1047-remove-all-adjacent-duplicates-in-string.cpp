class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(char &c : s) {
            if(!ans.empty() and c == ans.back()) ans.pop_back();
            else ans += c;
        }
        return ans;
    }
};