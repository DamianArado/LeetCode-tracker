class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(const string &detail : details) {
            string s = detail.substr(11, 2);
            if(stoi(s) > 60) ++ans;
        }
        return ans;
    }
};