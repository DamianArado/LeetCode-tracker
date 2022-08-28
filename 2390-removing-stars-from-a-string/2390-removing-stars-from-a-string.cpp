class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(char &c : s) {
            if(c != '*') ans += c;
            else ans.pop_back();
        }
        return ans;
    }
};